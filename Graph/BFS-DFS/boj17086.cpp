#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

struct info {
    int x;
    int y;
    int dist;

    info(int a, int b, int d) {
        x = a;
        y = b;
        dist = d;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    int mx = 0; // 안전거리의 최댓값
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // 상어가 있는 칸의 안전거리는 0
            if (board[i][j] == 1) continue;

            // BFS
            queue<info> q;
            vector<vector<int>> visited = vector<vector<int>>(n, vector<int>(m, 0));

            q.push(info(i, j, 0));
            visited[i][j] = true;

            while (!q.empty()) {
                int cx = q.front().x;
                int cy = q.front().y;
                int cd = q.front().dist;
                q.pop();

                if (board[cx][cy] == 1) {
                    mx = max(mx, cd);
                    break;
                }

                for (int k = 0; k < 8; ++k) {
                    int nx = cx + dx[k];
                    int ny = cy + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (visited[nx][ny]) continue;

                    q.push(info(nx, ny, cd+1));
                    visited[nx][ny] = true;
                }
            }
        }
    }

    cout << mx << "\n";

    return 0;
}