#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <climits>

#define MAX_NM 1'000

using namespace std;

int board[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM][2];

int n, m; // 행, 열

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    // BFS
    // 큐에 원소를 저장할 때 부쉈는지 여부도 함께 삽입
    queue<tuple<pair<int, int>, int, bool>> q; // {좌표, 거리, 부쉈는지}

    q.push({{0, 0}, 1, false});
    visited[0][0][0] = true;

    pair<int, int> point;
    int cnt;
    int result = INT_MAX;
    bool ruined;
    while (!q.empty()) {
        tie(point, cnt, ruined) = q.front();
        q.pop();

        int cx = point.first;
        int cy = point.second;

        if (cx == n-1 && cy == m-1) {
            if (cnt < result) result = cnt;
        }

        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if (board[nx][ny] == 1) {
                if (visited[nx][ny][ruined]) continue;
                if (ruined) continue;
                else { // 벽을 부수고 이동
                    q.push({{nx, ny}, cnt+1, true});
                    visited[nx][ny][1] = true;
                }
            } else { // board[nx][ny] == 0
                if (visited[nx][ny][ruined]) continue;
                q.push({{nx, ny}, cnt+1, ruined});
                visited[nx][ny][ruined] = true;
            }
        }
    }

    if (visited[n-1][m-1][0] || visited[n-1][m-1][1]) cout << result;
    else cout << -1;

    return 0;
}

// 반례 모음: https://www.acmicpc.net/board/view/107646
// 참고: https://kscodebase.tistory.com/66
// 피드백) visited를 ruined 여부에 따라 3차원으로 관리해야 함