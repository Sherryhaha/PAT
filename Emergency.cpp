//
// Created by sunguoyan on 16/4/7.
//

/*
 * 用深度优先解决
 */
#include<iostream>
#include<limits.h>
#define MAX 1024
using namespace std;


int ct,pmax,predist,n,visit[MAX],dis[MAX][MAX],Teamcount[MAX];;

void dfs(int p,int end,int d,int team){
    if(p==end){
        if(d<predist){
            predist = d;
            ct = 1;
            pmax = team;
        }
        else if(d==predist){
            ct++;
            if(team>pmax){
                pmax = team;
            }
        }
        return;
    }
    if(d > predist) return;

    int i;
    for(i = 0;i<n;i++){
        if(visit[i]==0&&dis[p][i]!=INT_MAX){
            visit[i] = 1;
            dfs(i,end,d+dis[p][i],team+Teamcount[i]);
            visit[i] = 0;
        }
    }

}

int main(){
    int m,start,end;
    int i,j;
    int c1,c2,d;
    predist = INT_MAX;
    ct = 0;
    cin>>n>>m>>start>>end;
    for(i = 0;i < n;i++){
        cin>>Teamcount[i];
    }
    for(i = 0;i < n;i++){
        visit[i]=0;
        for(j=0;j < n;j++){
            dis[i][j] = INT_MAX;
        }
    }
    for(i=0;i<m;i++){
        cin>>c1>>c2>>d;
        if(dis[c1][c2]>d){
            dis[c1][c2]=dis[c2][c1] = d;
        }
    }

    dfs(start,end,0,Teamcount[start]);
    cout<<ct<<" "<<pmax;
    return 0;
}