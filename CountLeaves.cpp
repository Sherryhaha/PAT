//
// Created by sunguoyan on 16/4/8.
//
#include<iostream>

using namespace std;

void dfs(int id,int level,int noch[],int child[][110],int n){
    int flag=0,i;
    if(noch[level]==-1) noch[level] = 0;
    for(i=1;i<=n;i++){
        if(child[id][i]==1){
            flag=1;
            if(level+1<=n){
                dfs(i,level+1,noch,child,n);
            }
        }
    }
    if(flag==0) noch[level]++;
}

int main(){
    int n,m,nochild[110],child[110][110],ID,k,tmp;
    int i,j;
    for(i=0;i<110;i++){
        nochild[i] = -1;
        for(j=0;j<110;j++){
            child[i][j] = 0;
        }
    }
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>ID>>k;
        for(j=0;j<k;j++){
            cin>>tmp;
            child[ID][tmp] = 1;
        }
    }

    dfs(1,1,nochild,child,n);

    for(i=1;i<=n;i++){
        if(nochild[i]>-1&&i==1){
            cout<<nochild[i];
        }
        else if(nochild[i]>-1){
            cout<<" "<<nochild[i];
        }
    }
    return 0;
}

