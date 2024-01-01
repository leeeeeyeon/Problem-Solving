#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k; // 세로, 가로, 음식물 쓰레기의 개수
    cin >> n >> m >> k;

    vector<vector<char>> board = vector(n+1, vector<char>(m+1, '.'));
    vector<vector<bool>> visited = vector(n+1, vector<bool>(m+1, false));

    int r, c;
    for (int i = 0; i < k; ++i) {
        cin >> r >> c;
        board[r][c] = '#';
    }

    queue<pair<int, int>> q;
    int cx, cy, nx, ny;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    int ret = 0; // 가장 큰 음식물의 크기
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (board[i][j] == '.') continue;

            // BFS
            q.push({i, j});
            visited[i][j] = true;
            int cnt = 1;

            while (!q.empty()) {
                cx = q.front().first;
                cy = q.front().second;
                q.pop();

                for (int l = 0; l < 4; ++l) {
                    nx = cx + dx[l];
                    ny = cy + dy[l];

                    if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
                    if (board[nx][ny] == '.') continue;
                    if (!visited[nx][ny]) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                        cnt ++;
                    }

                }
            }

            if (cnt > ret) ret = cnt;
        }
    }

    cout << ret;

    return 0;
}