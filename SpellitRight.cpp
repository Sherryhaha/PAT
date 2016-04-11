//
// Created by sunguoyan on 16/4/11.
//

#include<iostream>
using namespace std;

int main(){
    char num[101];
    char ten[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int i,sum;
    int pa,pb,pc;
    sum = 0;
    scanf("%s",num);
//    cin>>num;
    for(i=0;num[i]!='\0';i++){
        sum += (num[i]-'0');
    }
    if(sum>=0&&sum<=9){
        cout<<ten[sum];
    }
    else if(sum>=10&&sum<=99){
        pa = sum/10;
        pb = sum%10;
        cout<<ten[pa]<<" "<<ten[pb];
    }
    else{
        pa = sum/10;
        pc = sum%10;
        sum = sum/10;
        pa = sum/10;
        pb = sum%10;
        cout<<ten[pa]<<" "<<ten[pb]<<" "<<ten[pc];
    }
    return 0;
}

