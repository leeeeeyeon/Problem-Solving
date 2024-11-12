#include <iostream>
#include <vector>

#define MAX_N 6

using namespace std;

int n; // board의 크기
char board[MAX_N][MAX_N];
vector<pair<int, int>> teachers; // 선생님 좌표
bool canHideAll;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 모든 학생들을 감시로부터 피하도록 할 수 있는지
bool hideFromTeacher() {
    for (auto teacher : teachers) {
        int cx = teacher.first;
        int cy = teacher.second;

        for (int k = 0; k < 4; k++) {
            int i = 1;
            while (true) {
                int nx = cx + dx[k]*i;
                int ny = cy + dy[k]*i;

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                if (board[nx][ny] == 'O') break;

                if (board[nx][ny] == 'S') return false;

                i++;
            }
        }
    }

    return true;
}

void backtracking(int cnt) {
    if (cnt == 3) {
        if (hideFromTeacher()) canHideAll = true;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'X') {
                board[i][j] = 'O';
                backtracking(cnt+1);
                board[i][j] = 'X';
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];

            if (board[i][j] == 'T') teachers.push_back({i, j});
        }
    }

    backtracking(0);

    if (canHideAll) cout << "YES";
    else cout << "NO";

    return 0;
}