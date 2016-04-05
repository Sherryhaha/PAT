//
// Created by sunguoyan on 16/4/5.
//

/**
 * 将A+B并将答案以三个一组的格式显示
 * 用了两种方法，第一种是数组的形式，第二种是 string的形式，需要注意的是，第二种string形式需要包含
 * 头文件#include<algorithm>
 */
#include<iostream>
using namespace std;

//int main(){
//    long a,b,sum,i,flag;
//    bool is_positive;
//    char result[9];
//    while(cin>>a>>b){
//        sum = a+b;
//        flag = 0;
//        if(sum > 0||sum == 0){
//            is_positive = true;
//        }
//        else if(sum < 0){
//            is_positive = false;
//        }
//        if(abs(sum)>=1000){
//            sum = abs(sum);
//            for(i=0;sum>0;i++){
//                result[i]=sum%10+'0';
//                sum = sum/10;
//                if(flag==2&&sum!=0){
//                    i++;
//                    result[i]=',';
//                    flag=0;
//                }
//                else{
//                    flag++;
//                }
//            }
//            if(is_positive== false){
//                cout<<'-';
//            }
//            i--;
//            for(;i>=0;i--){
//                cout<<result[i];
//            }
//            cout<<endl;
//        }
//        else{
//            cout<<sum<<endl;
//        }
//    }
//    return 0;
//}

int main(){
    long a,b,sum,i,flag;
    bool is_positive;
    char tmp;
    while(cin>>a>>b){
        sum = a+b;
        flag = 0;
        string result;
        if(sum > 0||sum == 0){
            is_positive = true;
        }
        else if(sum < 0){
            is_positive = false;
        }
        if(abs(sum)>=1000){
            sum = abs(sum);
            for(i=0;sum>0;i++){
                tmp=sum%10+'0';
                result.push_back(tmp);
                sum = sum/10;
                if(flag==2&&sum!=0){
                    i++;
                    result.push_back(',');
                    flag=0;
                }
                else{
                    flag++;
                }
            }
            if(is_positive== false){
                cout<<'-';
            }
            reverse(result.begin(),result.end());

            cout<<result<<endl;
        }
        else{
            cout<<sum<<endl;
        }
    }
    return 0;
}
