#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y, int cnt, int sum, vvi &board, vvb &visited, int ret) {
    // 종료 조건
    if (cnt == 3) {
        return max(ret, sum);
    }

    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (visited[nx][ny]) continue;

        visited[nx][ny] = true;
        ret = dfs(nx, ny, cnt+1, sum+board[nx][ny], board, visited, ret);
        visited[nx][ny] = false;
    }

    return ret;
}

int tBlock(int sx, int sy, vvi &board) {
    vvi square = vvi(3, vector<int>(3, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            square[i][j] = board[sx+i][sy+j];
        }
    }

    return max({square[0][0] + square[0][1] + square[0][2] + square[1][1],
                square[1][0] + square[1][1] + square[1][2] + square[0][1],
                square[1][0] + square[1][1] + square[1][2] + square[2][1],
                square[2][0] + square[2][1] + square[2][2] + square[1][1],
                square[0][0] + square[1][0] + square[2][0] + square[1][1],
                square[0][1] + square[1][1] + square[2][1] + square[1][0],
                square[0][1] + square[1][1] + square[2][1] + square[1][2],
                square[0][2] + square[1][2] + square[2][2] + square[1][1]});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vvi board = vvi(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    int ret = 0;
    vvb visited = vvb(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // DFS + 백트래킹
            visited[i][j] = true;
            int sum = dfs(i, j, 0, board[i][j], board, visited, 0);
            ret = max(ret, sum);
            visited[i][j] = false;
        }
    }

    for (int i = 0; i <= n-3; ++i) {
        for (int j = 0; j <= m-3; ++j) {
            ret = max(ret, tBlock(i, j, board));
        }
    }

    cout << ret << "\n";

    return 0;
}

// 피드백 1: 백트래킹을 통해 visited 배열은 초기화되므로 이중 for문마다 visited 배열을 선언하지 않아도 된다