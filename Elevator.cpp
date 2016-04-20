//
// Created by sunguoyan on 16/4/20.
//

#include<iostream>

using namespace std;

int main() {
    int N, num[1000], i;
    int tmp1,tmp2,sum,tmp;
    sum = 0;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin>>num[i];
    }
    tmp1 = num[0];
    tmp1 = num[0]-0;
    if(tmp1>0){
        sum = tmp1*6+5;
    }
    if(tmp1==0){
        sum = 5;
    }
    for(i=1;i<N;i++){
        tmp1 = num[i-1];
        tmp2 = num[i];
        tmp = tmp2-tmp1;
        if(tmp>0){
            sum+=tmp*6+5;
        }
        if(tmp<0){
            sum+=-tmp*4+5;
        }
        if(tmp==0){
            sum=sum+5;
        }
    }
    cout<<sum<<endl;
    return 0;
}