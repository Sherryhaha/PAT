//
// Created by sunguoyan on 16/7/25.
// 栈的考验，判断出栈顺序
//两个判断条件，1.当前的出栈数值－已经执行过的出栈次数＝当前栈中的元素数量。2.若数据m出栈后，则在m之后出栈的元素若小于m，则它们是按递减排序的。
//

#include<iostream>
#include<string>

using namespace std;

//int main() {
//    int M, N, K;
//    cin >> M >> N >> K;
//    int i, j, k;
//    int a[1001];
//    int flag;
//    string result[1001];
//
//    for (k = 0; k < K; k++) {
//        flag = 0;
//        for (j = 0; j < N; j++) {
//            cin >> a[j];
//        }
//        if (N > M) {
//            for (i = 0, j = 0; i < N - M; i++, j++) {
//                if (a[i] > M + j) {
//                    flag = 1;
//                    result[k] = "NO";
//                    break;
//                }
//            }
//        }
//        if (flag == 1) {
//            continue;
//        }
//        for (i = 0; i < N; i++) {
//            if (a[i] == N) {
//                for (j = i + 1; j + 1 < N; j++) {
//                    if (a[j + 1] > a[j]) {
//                        flag = 1;
//                        result[k] = "NO";
//                        break;
//                    }
//                }
//            }
//            if (flag == 1) {
//                break;
//            }
//        }
//
//        if (flag == 1) {
//            continue;
//        } else {
//            result[k] = "YES";
//        }
//
//    }
//
//    for (i = 0; i < K; i++) {
//        cout << result[i] << endl;
//    }
//    return 0;
//}

int main() {
    int M, N, K;
    int tmp, max, lmax;

    int i;
    bool flag;

    cin >> M >> N >> K;
    while (K--) {
        flag = true;
        max = 0;
        lmax = 1001;

        for (i = 0; i < N; ++i) {
            cin >> tmp;
            if (tmp > max) {
                if (tmp - i > M) {
                    flag = false;
//                    break;
                }
                else {
                    max = lmax = tmp;
                }
            } else {
                if (tmp > lmax) {
                    flag = false;
//                    break;
                } else {
                    lmax = tmp;
                }
            }
//            if(!flag ){
//                break;
//            }
        }

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}