#include <bits/stdc++.h>

using namespace std;

int calculate(int a, int b, int cmd) {
    switch (cmd) {
        case 0:
            return a + b;
        case 1:
            return a - b;
        case 2:
            return a * b;
        case 3:
            return a / b;
        default:
            return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 수의 개수
    cin >> n;

    vector<int> v = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<int> operators;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int i = 0; i < a; ++i) {
        operators.push_back(0); // +
    }
    for (int i = 0; i < b; ++i) {
        operators.push_back(1); // -
    }
    for (int i = 0; i < c; ++i) {
        operators.push_back(2); // *
    }
    for (int i = 0; i < d; ++i) {
        operators.push_back(3); // /
    }

    int mx = INT_MIN;
    int mn = INT_MAX;

    // 1. next_permutation으로 순열을 구함
    sort(operators.begin(), operators.end());

    // 2. 순열로 구한 연산자 순서에 따라 식의 결과 계산
    // 3. 최댓값과 최솟값 갱신
    do {
        int ret = v[0];
        for (int i = 0; i < operators.size(); ++i) {
            ret = calculate(ret, v[i+1], operators[i]);
        }

        mx = max(mx, ret);
        mn = min(mn, ret);
    } while (next_permutation(operators.begin(), operators.end()));

    cout << mx << "\n" << mn << "\n";

    return 0;
}