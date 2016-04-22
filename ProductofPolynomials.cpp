//
// Created by sunguoyan on 16/4/22.
//

#include<iostream>
#include<iomanip> //控制浮点数输出的位数

using namespace std;

int main() {
    double A[10000], B[10000], C[10000];
    int k, tmp, expo, expo1, expo2, k1, k2, i, j;
    int N = 10000;
    double co, co1, co2;
    k = 0;
    tmp = 0;
    for(i = 0;i<N;i++){
        A[i] = 0;
        B[i] = 0;
        C[i] = 0;
    }
    cin >> k1;
    for (i = 0; i < k1; i++) {
        cin >> expo;
        cin>>co;
        A[expo] = co;
    }
    cin >> k2;
    for (i = 0; i < k2; i++) {
        cin >> expo;
        cin>>co;
        B[expo] = co;
    }
    for (i = 0; i < N; i++) {
        if (A[i] != 0) {
            tmp++;
            co1 = A[i];
            expo1 = i;
            for (j = 0; j < N; j++) {
                if (B[j] != 0) {
                    co2 = B[j];
                    expo2 = j;
                    co = co1 * co2;
                    expo = expo1 + expo2;
                    C[expo] += co;

                }
            }
        }
    }
    for (i = 0; i < N; i++) {
        if (C[i] != 0) {
            k++;
        }
    }
    cout << k;
    for (i = N-1; i >=0; i--) {
        if (C[i] == 0) {
            continue;
        }
        else{
            cout << " " << i <<" "<< fixed << setprecision(1) << C[i];
        }

    }
//    cout<<tmp;
    return 0;
}