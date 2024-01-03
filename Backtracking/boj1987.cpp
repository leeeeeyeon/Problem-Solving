#include <bits/stdc++.h>

using namespace std;

int r, c;
char board[22][22];

bool visited[26];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ret;

// 인접한 네 칸 중 이동할 칸이 있는지 확인
bool canGo(int cx, int cy) {
    int nx, ny;
    bool cg = false;
    for (int i = 0; i < 4; ++i) {
        nx = cx + dx[i];
        ny = cy + dy[i];

        // index out of range
        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        // 이미 지나온 알파벳
        if (visited[board[nx][ny]-'A']) continue;
        cg = true;
    }

    return cg;
}

void dfs(int cx, int cy, int cnt) {
    // 종료 조건: 더 이상 진전할 칸이 없을 때
    if (!canGo(cx, cy)) {
        if (cnt > ret) ret = cnt;
        visited[board[cx][cy]-'A'] = false;
        return;
    }

    int nx, ny;
    for (int i = 0; i < 4; ++i) {
        nx = cx + dx[i];
        ny = cy + dy[i];

        // index out of range
        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        // 이미 지나온 알파벳
        if (visited[board[nx][ny]-'A']) continue;

        visited[board[nx][ny]-'A'] = true;
        dfs(nx, ny, cnt+1);
        visited[board[nx][ny]-'A'] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> board[i][j];
        }
    }

    visited[board[0][0]-'A'] = true;
    dfs(0, 0, 1);

    cout << ret;

    return 0;
}