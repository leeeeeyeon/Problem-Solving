#include <bits/stdc++.h>

using namespace std;

int n, m; // 세로, 가로
int board[103][103] = {-1,};
queue<pair<int, int>> q;
string s;
int ret;

int x, y;
int nx, ny;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            board[i][j] = s[j] - '0';
        }
    }

    // 시작점을 큐에 삽입
    q.push({0, 0});

    // 큐가 빌 때까지 BFS를 진행
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            nx = x+dx[i];
            ny = y+dy[i];

            // index를 벗어나지 않는 경우
            if (nx >= 0 && nx < n && ny >=0 && ny < m) {
                if(board[nx][ny] == 1) {
                    if (nx == 0 && ny == 0) continue;
                    board[nx][ny] += board[x][y];
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << board[n-1][m-1] << "\n";

    return 0;
}