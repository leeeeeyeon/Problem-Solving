#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

typedef long long ll;
typedef vector<vector<int>> vvi;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vvi board = vvi(n, vector<int>(m, 0));
    vvi answer = vvi(n, vector<int>(m, INF));

    int sx = 0;
    int sy = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                sx = i;
                sy = j;
                answer[i][j] = 0;
            }
        }
    }

    // BFS
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == 0) continue;

            if (answer[cx][cy]+1 < answer[nx][ny]) {
                answer[nx][ny] = answer[cx][cy]+1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) cout << 0 << ' ';
            else if (answer[i][j] >= INF) cout << -1 << ' ';
            else cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}