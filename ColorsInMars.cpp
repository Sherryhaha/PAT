//
// Created by sunguoyan on 16/7/22.
//

#include<iostream>
using namespace std;

int main(){
   // int A,B,C,a1,a2,b1,b2,c1,c2;
    int in[3];
    int a1[3],a2[3];
    int b1[3],b2[3];
//    char a11,a22,b11,b22,c11,c22;
    int radix = 13;
//    char num[3]={'A','B','C'};
    int i;
    for(i = 0;i<3;i++){
        cin>>in[i];
        a1[i] = in[i]/radix;
        a2[i] = in[i]%radix;
    }

    int tmp;
    for(i = 0;i<3;i++){
        if(a1[i]<10){
            tmp = a1[i]+48;
            b1[i]=tmp;
//            cout<<(char)tmp<<endl;
        }
        else{
            tmp = a1[i]+55;
            b1[i] = tmp;
        }
        if(a2[i]<10){
            tmp = a2[i]+48;
            b2[i]=tmp;
//            cout<<(char)tmp<<endl;
        }
        else{
            tmp = a2[i]+55;
            b2[i] = tmp;
        }
    }

    cout<<"#"<<(char)b1[0]<<(char)b2[0]<<(char)b1[1]<<(char)b2[1]<<(char)b1[2]<<(char)b2[2];
    return 0;
}
