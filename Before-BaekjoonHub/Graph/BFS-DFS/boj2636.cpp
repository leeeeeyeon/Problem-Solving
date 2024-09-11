#include <bits/stdc++.h>

using namespace std;

int r, c; // 행, 열

int v[101][101];
bool check[101][101];

int t; // 모두 녹아서 없어지는 데 걸리는 시간
int ret; // 모두 녹기 한 시간 전에 남아있는 치즈 조각

int cx, cy, nx, ny;
int dx[4] = {0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};

// 판에 있는 치즈의 개수를 세는 함수
int countCheese() {
    int cheese = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (v[i][j] == 1) cheese++;
        }
    }

    return cheese;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    // 입력
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> v[i][j];
        }
    }

    // while문을 1번 돌 때마다 1시간이 지남
    while (true) {
        int tmp = countCheese();

        // 남아있는 치즈가 없다면 while문 종료
        if (tmp == 0) break;
            // 현재 치즈의 개수를 ret에 저장
        else ret = tmp;

        queue<pair<int, int>> q;
        memset(check, false, sizeof(check));

        // (0, 0)부터 시작해서 치즈 밖의 공간을 찾는다
        q.push({0, 0});
        check[0][0] = true;
        while (!q.empty()) {
            cx = q.front().first;
            cy = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                nx = cx + dx[i];
                ny = cy + dy[i];

                if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;

                if (!check[nx][ny] && v[nx][ny] == 0) {
                    check[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        // 치즈가 공기에 닿아 녹는다
        // 가장자리에는 치즈가 없으므로 1부터 시작
        for (int i = 1; i < r-1; ++i) {
            for (int j = 1; j < c-1; ++j) {
                // 치즈가 없는 칸은 skip
                if (v[i][j] == 0) continue;

                // 치즈이면서 인접한 위치 중 하나라도 밖이면 녹는다
                for (int k = 0; k < 4; ++k) {
                    nx = i + dx[k];
                    ny = j + dy[k];

                    // v[nx][ny] == 0으로 하면 안됨
                    if (check[nx][ny]) {
                        // 치즈가 녹는 것을 표현
                        v[i][j] = 0;
                        break;
                    }
                }
            }
        }
        t++;
    }

    cout << t << "\n";
    cout << ret << "\n";
    return 0;
}

/*
 * 피드백) (0, 0)에서 시작하여 BFS를 돌며 치즈 밖의 공간을 찾으면 치즈 안의 공간과 밖의 공간을 나눌 수 있다.
 * */
