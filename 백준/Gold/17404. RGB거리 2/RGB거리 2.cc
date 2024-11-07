#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<vector<int>> vvi;

void colorHouse(vvi &dp, vvi &arr) {
    for (int i = 1; i < dp.size(); i++) {
        dp[i][0] = arr[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = arr[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = arr[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vvi arr = vvi(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    vvi redDP = arr; // N번 집 색이 빨강일 때
    vvi blueDP = arr; // N번 집 색이 파랑일 때
    vvi greenDP = arr; // N번 집 색이 초록일 때

    // 1번 집의 R, G, B를 INF로 만든다
    redDP[0][0] = INT_MAX;
    blueDP[0][1] = INT_MAX;
    greenDP[0][2] = INT_MAX;

    // DP
    colorHouse(redDP, arr);
    colorHouse(blueDP, arr);
    colorHouse(greenDP, arr);

    cout << min({redDP[n-1][0], blueDP[n-1][1], greenDP[n-1][2]});
    return 0;
}