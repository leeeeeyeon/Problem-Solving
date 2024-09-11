#include <bits/stdc++.h>

using namespace std;

int t, w; // T초 동안 최대 W번 움직임
int v[1001];
int dp[31][2][1001];
// dp[이동 횟수][자두의 위치][흐른 시간]
// 참고) 1번 나무의 인덱스는 0, 2번 나무의 인덱스는 1

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t >> w;

    for (int i = 1; i <= t; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i <= w; ++i) { // 움직인 횟수
        for (int j = 1; j <= t; ++j) { // 초
            // 아예 안 움직였을 때는 항상 1번 나무 아래에 위치
            if (i == 0) {
                dp[i][0][j] = dp[i][0][j-1] + (v[j] == 1);
            }
            else {
                // 현재 위치까지 받은 누적 자두 = max(안 움직였을 때, 움직였을 때) + (현재 위치에서 받은 자두)

                // 1번 나무
                dp[i][0][j] = max(dp[i][0][j-1], dp[i-1][1][j-1]) + (v[j] == 1);
                // 2번 나무
                dp[i][1][j] = max(dp[i][1][j-1], dp[i-1][0][j-1]) + (v[j] == 2);
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < 2; ++i) { // 자두 나무 번호
        for (int j = 0; j <= w; ++j) { // 움직인 횟수
            ret = max(ret, dp[j][i][t]);
        }
    }
    cout << ret << "\n";

    return 0;
}

/*
 * 피드백 1) 관리해야 할 상태가 3가지(이동 횟수, 자두의 위치, 흐른 시간)이기 때문에 3차원 배열로 DP 값을 저장
 * */