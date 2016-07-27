//
// Created by sunguoyan on 16/7/27.
//

#include<iostream>
using namespace std;

int main(){
    string S1,S2;
    int i;
    int tmp[128]={0};
    char t;
    int k;
//    tmp[128]={0};   一开始错在这里了，在这里赋予0值只会给数组的第一个元素赋予0值

    getline(cin,S1);
    getline(cin,S2);

    for(i = 0;i<S2.length();i++){
        t = S2[i];
        k = (int)t;

        tmp[k] = 1;
    }
    for(i = 0;i<S1.length();i++){
        t = S1[i];
        k = (int)t;

        if(tmp[k]==0){
            cout<<t;
        }
    }
    cout<<endl;
    return 0;
}