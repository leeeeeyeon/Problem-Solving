#include <bits/stdc++.h>

using namespace std;

int n;
int ret;
int board[500][500];
int dp[500][500];

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> board[i][j];
        }
    }

    dp[0][0] = board[0][0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) dp[i][j] = dp[i-1][j] + board[i][j];
            if (j == i) dp[i][j] = dp[i-1][j-1] + board[i][j];
            else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + board[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dp[n-1][i] > ret) ret = dp[n-1][i];
    }

    cout << ret << endl;

    return 0;
}