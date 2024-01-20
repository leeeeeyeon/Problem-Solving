#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, k;
int board[20][20];
vector<int> dice = vector<int>(7);
int command;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int nx, ny;

vector<int> tumble(int cmd) {
    vector<int> newDice = vector<int>(7);
    switch (command) {
        case 1: // 동
            newDice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
            break;
        case 2: // 서
            newDice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
            break;
        case 3: // 북
            newDice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
            break;
        case 4: // 남
            newDice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
            break;
    }

    return newDice;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < k; ++i) {
        cin >> command;
        nx = x + dx[command];
        ny = y + dy[command];

        // 바깥으로 이동시키려고 하는 경우 skip
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        dice = tumble(command);
        if (board[nx][ny] == 0) board[nx][ny] = dice[6];
        else {
            dice[6] = board[nx][ny];
            board[nx][ny] = 0;
        }
        x = nx;
        y = ny;

        cout << dice[1] << endl;
    }
    return 0;
}