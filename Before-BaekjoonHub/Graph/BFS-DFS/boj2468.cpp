#include <bits/stdc++.h>

using namespace std;

int n;
int arr[101][101];
bool visited[101][101];
int mx; // 최대 강수량
queue<pair<int, int>> q;
int ret; // 안전 영역의 최대 개수

int cx, cy, nx, ny;
int dx[4] = {0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            mx = max(mx, arr[i][j]);
        }
    }

    for (int r= 0; r <= mx; ++r) {
        int safe = 0; // 강수량이 rain일 때 안전 영역의 개수
        // visited 배열 초기화
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // BFS
                if (visited[i][j] || arr[i][j] <= r) continue;

                // 시작점
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    cx = q.front().first;
                    cy = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; ++k) {
                        nx = cx + dx[k];
                        ny = cy + dy[k];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] <= r) continue;

                        if (!visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                safe ++;
            }
        }
        ret = max(ret, safe);
    }

    cout << ret << "\n";

    return 0;
}

/*
 * '아무 지역도 물에 잠기지 않을 수도 있다.' 비가 안 올 경우도 고려해야 한다는 뜻이다.
 * 처음에는 모든 지역이 높아서 물에 안 잠긴다고 생각했음 ㅋㅋ ㅠㅠ
 * */