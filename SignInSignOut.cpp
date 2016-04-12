//
// Created by sunguoyan on 16/4/12.
//

#include<iostream>
using namespace std;


struct Record{
    string ID;
    int  SignIn;
    int  SignOut;
};

int main(){
    struct Record tmp,in,out;
    string unlock,lock;
    int m,i;
    char c;
    int h1,h2,h3,h4,h5,h6;
    cin>>m;
    cin>>tmp.ID>>h1>>c>>h2>>c>>h3>>h4>>c>>h5>>c>>h6;
    tmp.SignIn = h1*3600+h2*60+h3;
    tmp.SignOut = h4*3600+h5*60+h6;
    in = out = tmp;
    for(i = 1;i < m;i++){
        cin>>tmp.ID>>h1>>c>>h2>>c>>h3>>h4>>c>>h5>>c>>h6;
        tmp.SignIn = h1*3600+h2*60+h3;
        tmp.SignOut = h4*3600+h5*60+h6;
        if(tmp.SignIn<in.SignIn){
            in = tmp;
        }
        if(tmp.SignOut>out.SignOut){
            out = tmp;
        }
    }
    cout<<in.ID<<" "<<out.ID;
    return 0;
}