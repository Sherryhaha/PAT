//
// Created by sunguoyan on 16/7/28.
// PAT 1092
//

#include<iostream>
using namespace std;

int main(){
    string S1,S2;
    getline(cin,S1);   //读入商店老板拥有的玻璃串
    getline(cin,S2);   //读入客户需要的玻璃串
    int tmp[62]={0};   //存储商店玻璃串
    int src[62]={0};   //存储客户玻璃串
    int less,more,i;
    bool flag;
    int t;

    less = 0;
    more = 0;
    flag = true;
    //对商店的玻璃串计数
    for(i=0;i<S1.length();i++){
        t = (int)S1[i];
//        cout<<t<<" ";
        if(t>47&&t<58){
            tmp[t-48]++;
        }
        if(t>96&&t<123){
            tmp[t-87]++;
        }
        if(t>64&&t<91){
            tmp[t-29]++;
        }
    }
//    cout<<endl;
    //对客户需要的玻璃串计数
    for(i=0;i<S2.length();i++){
        t = (int)S2[i];
//        cout<<t<<" ";
        if(t>47&&t<58){
            src[t-48]++;
        }
        if(t>96&&t<123){
            src[t-87]++;
        }
        if(t>64&&t<91){
            src[t-29]++;
        }
    }

//    cout<<endl;
    for(i=0;i<62;i++){
        if(tmp[i]>src[i]){
            more = more + (tmp[i]-src[i]);
        }
        if(src[i]!=0&&tmp[i]<src[i]){
            less = less + (src[i]-tmp[i]);
            flag = false;
        }
    }


    if(flag){
        cout<<"Yes "<<more<<endl;
    }else{
        cout<<"No "<<less<<endl;
    }


    return 0;


}