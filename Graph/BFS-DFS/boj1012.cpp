#include <bits/stdc++.h>

using namespace std;

int t;
int m, n, k;
int x, y;
int arr[54][54];
bool visited[54][54];
queue<pair<int, int>> q;
int ret;
int cx, cy;
int nx, ny;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    cin >> t;

    for (int a = 0; a < t; ++a) {
        // 초기화
        ret = 0;

        memset(arr, false, sizeof(arr));
        memset(visited, false, sizeof(visited));

        // 가로, 세로, 배추의 위치
        cin >> m >> n >> k;

        // 입력
        for (int i = 0; i < k; ++i) {
            cin >> y >> x;
            arr[x][y] = 1;
        }

        // BFS
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited[i][j] || arr[i][j] == 0) continue;

                q.push({i, j});
                while (!q.empty()) {
                    cx = q.front().first;
                    cy = q.front().second;
                    q.pop();

                    for (int l = 0; l < 4; ++l) {
                        nx = cx + dx[l];
                        ny = cy + dy[l];

                        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                            if (arr[nx][ny] == 1 && !visited[nx][ny]) {
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
                ret++;
            }
        }

        cout << ret << "\n";
    }
    return 0;
}
