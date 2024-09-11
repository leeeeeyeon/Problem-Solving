#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> vvi;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool canClean(int cx, int cy, vvi &board) {
    for (int i = 0; i < 4; ++i) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        if (nx < 0 || ny < 0 || nx > board.size() || ny > board[0].size()) continue;

        if (board[nx][ny] == 0) return true;
    }

    return false;
}

bool isZero(int cx, int cy, int d, vvi &board) {
    int nx = cx + dx[d];
    int ny = cy + dy[d];

    if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) return false;

    if (board[nx][ny] == 0) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int r, c, d;
    cin >> r >> c >> d;

    vvi board = vvi(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    int cnt = 0;
    if (board[r][c] == 0) {
        board[r][c] = 2;
        cnt++;
    }

    // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없고, 뒤쪽 칸이 벽이라 후진할 수 없으면 작동을 멈춘다
    // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있거나 한 칸 후진해서 있는 경우
    while (true) {
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                cout << board[i][j] << " ";
//            }
//            cout << endl;
//        }

        // 현재 위치
        int cx = r;
        int cy = c;

        // 바라보는 쪽에 0이 있을 때까지
        if (canClean(cx, cy, board)) {
            do {
                // d를 바꿔준다
                if (d == 0) d = 3;
                else d--;
            } while (!isZero(cx, cy, d, board));

            int nx = cx + dx[d];
            int ny = cy + dy[d];

            // 청소를 완료했다는 뜻
            board[nx][ny] = 2;
            cnt ++;

            // while문을 수행할 수 있도록 변수 대입
            r = nx;
            c = ny;
        } else {
            int bd;
            if (d <= 1) {
                bd = d + 2;
            } else {
                bd = d - 2;
            }

            int nx = cx + dx[bd];
            int ny = cy + dy[bd];

            if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) break;
            if (board[nx][ny] == 1) break;

            // 0 또는 1이 나올 때까지 계속 후진
            r = nx;
            c = ny;
        }

//        cout << "cnt: " << cnt << endl;
//        cout << endl;
    }

    cout << cnt << "\n";

    return 0;
}

// nx, ny라고 적어야 하는데 nx, nx라고 적음
// 푸는 것은 1시간 정도 썼으나 실수를 수정하는데 20분 소요 >>> 총 1시간 20분 갸랑 소요