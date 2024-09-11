#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int board[2][100000];
int dp[2][100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--) {
        // 입력
        cin >> n;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }

        // DP 배열 초기화
        memset(dp, 0, sizeof(dp));
        dp[0][0] = board[0][0];
        dp[1][0] = board[1][0];
        dp[0][1] = dp[1][0] + board[0][1];
        dp[1][1] = dp[0][0] + board[1][1];

        // DP 진행
        for (int i = 2; i < n; ++i) {
            dp[0][i] = max(dp[1][i-1] + board[0][i], max(dp[0][i-2], dp[1][i-2]) + board[0][i]);
            dp[1][i] = max(dp[0][i-1] + board[1][i], max(dp[0][i-2], dp[1][i-2]) + board[1][i]);
        }

        cout << max(dp[0][n-1], dp[1][n-1]) << "\n";
    }
    return 0;
}