#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;

    cin >> a >> b >> c;

    int sum = 0; // 상근이가 내야하는 주차 요금

    int arr[100] = {0};

    for (int i = 0; i < 3; ++i) {
        int start, end;
        cin >> start >> end;

        // 도착한 시간은 포함하고 떠난 시간은 포함하지 않는다
        for (int j = start; j < end; ++j) {
            arr[j] ++;
        }
    }

    for (int elem : arr) {
        if (elem == 0) continue;
        else if (elem == 1) sum += a;
        else if (elem == 2) sum += b * 2;
        else sum += 3 * c;
    }

    cout << sum << '\n';

    return 0;
}