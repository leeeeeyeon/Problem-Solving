#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr = vector<int>(n);
    vector<int> dp = vector<int>(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(dp[1], max(dp[0] + arr[2], arr[1] + arr[2]));

    for (int i = 3; i < n; ++i) {
        dp[i] = max({dp[i-1], dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]});
    }

    cout << dp[n-1] << "\n";
}

// 피드백) max 함수를 사용할 때 인자를 3개 이상 하려면 {}로 감싸주어야 한다