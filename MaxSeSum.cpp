//
// Created by sunguoyan on 16/4/13.
//

#include<iostream>

using namespace std;

int main() {
    int n, i, j, tmp, sum, start, end;
    int num[10000];
    int count = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> num[i];
        if (num[i] > 0||num[i] ==0) count++;
    }
    if (count == 0) {
        cout << "0" << " " << num[0] << " " << num[n - 1];
        return 0;
    }
    sum = -1;
    for (i = 0; i < n; i++) {
        tmp = 0;
        for (j = i; j < n; j++) {
            tmp = tmp + num[j];
            if (tmp > sum) {
                sum = tmp;
                start = num[i];
                end = num[j];
            }
        }
    }
    cout << sum << " " << start << " " << end<<endl;

    return 0;
}