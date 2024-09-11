#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int b, c;
    cin >> b >> c;

    long long ret = n; // 총 감독관은 n명 필요
    for (int i = 0; i < n; ++i) {
        arr[i] -= b;
        if (arr[i] <= 0) continue;
        if (arr[i] % c == 0) {
            ret += arr[i] / c;
        } else {
            ret += arr[i] / c + 1;
        }
    }

    cout << ret << "\n";

    return 0;
}

// 피드백 1: ret은 int 범위를 넘을 수 있다
// 피드백 2: arr[i]가 b보다 작을수도 있다