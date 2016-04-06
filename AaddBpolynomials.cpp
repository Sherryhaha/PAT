//
// Created by sunguoyan on 16/4/6.
//
#include<iostream>
#include<iomanip> //控制浮点数输出的位数
using namespace std;
#define max 1024

int main(){
    int k1,k2;
    int i,e;
    double co;
    double a[max]={0};
    cin>>k1;
    for(i = 0; i < k1;i++){
        cin>>e>>co;
        a[e]=co;
    }

    cin>>k1;
    for(i=0;i<k1;i++){
        cin>>e>>co;
        a[e] = a[e]+co;
    }

    k2=0;
    for(i=0;i<max;i++){
        if(a[i]!=0) k2++;
    }
    cout<<k2;
    for(i =max - 1;i>=0;i--){
        if(a[i]!=0){
            cout<<" "<<i<<" "<<fixed<<setprecision(1)<<a[i];
        }
    }
    return 0;
}
