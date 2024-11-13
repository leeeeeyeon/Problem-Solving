#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<pair<int, pair<int, int>>> vpip; // {감시 유형, 좌표}

int n, m;
int answer;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int countSafeZone(vvi board) {
    int result = 0;

    for (int i = 0; i <n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) result++;
        }
    }

    return result;
}

void backtracking(int idx, vvi board, vpip cctv) {
    // 모든 CCTV 감시 표시 완료
    if (idx == cctv.size()) {
        // 사각 지대의 크기를 count
        int safeZone = countSafeZone(board);

        // answer 갱신
        answer = min(answer, safeZone);

        // 재귀 탈출
        return;
    }

    // idx번째 CCTV 감시 표시
    int cx = cctv[idx].second.first;
    int cy = cctv[idx].second.second;
    vvi newBoard = board;
    if (cctv[idx].first == 1) {
        for (int k = 0; k < 4; k++) {
            newBoard = board;
            int i = 1;
            while (true) {
                int nx = cx + dx[k] * i;
                int ny = cy + dy[k] * i;

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                else if (newBoard[nx][ny] == 6) break;

                if (newBoard[nx][ny] == 0) newBoard[nx][ny] = -1;
                i++;
            }

            backtracking(idx+1, newBoard, cctv);
        }
    } else if (cctv[idx].first == 2) {
        vector<vector<int>> directions = {{1, 3}, {0, 2}};
        for (auto dir : directions) {
            newBoard = board;
            for (int k = 0; k < dir.size(); k++) {
                int i = 1;
                while (true) {
                    int nx = cx + dx[dir[k]] * i;
                    int ny = cy + dy[dir[k]] * i;

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                    else if (newBoard[nx][ny] == 6) break;

                    if (newBoard[nx][ny] == 0) newBoard[nx][ny] = -1;
                    i++;
                }
            }

            backtracking(idx+1, newBoard, cctv);
        }
    } else if (cctv[idx].first == 3) {
        vector<vector<int>> directions = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
        for (auto dir : directions) {
            newBoard = board;
            for (int k = 0; k < dir.size(); k++) {
                int i = 1;
                while (true) {
                    int nx = cx + dx[dir[k]] * i;
                    int ny = cy + dy[dir[k]] * i;

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                    else if (newBoard[nx][ny] == 6) break;

                    if (newBoard[nx][ny] == 0) newBoard[nx][ny] = -1;
                    i++;
                }
            }

            backtracking(idx+1, newBoard, cctv);
        }
    } else if (cctv[idx].first == 4) {
        vector<vector<int>> directions = {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}};
        for (auto dir : directions) {
            newBoard = board;
            for (int k = 0; k < dir.size(); k++) {
                int i = 1;
                while (true) {
                    int nx = cx + dx[dir[k]] * i;
                    int ny = cy + dy[dir[k]] * i;

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                    else if (newBoard[nx][ny] == 6) break;

                    if (newBoard[nx][ny] == 0) newBoard[nx][ny] = -1;
                    i++;
                }
            }

            backtracking(idx+1, newBoard, cctv);
        }
    } else { // cctv[idx].first == 5
        for (int k = 0; k < 4; k++) {
            int i = 1;
            while (true) {
                int nx = cx + dx[k] * i;
                int ny = cy + dy[k] * i;

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                else if (newBoard[nx][ny] == 6) break;

                if (newBoard[nx][ny] == 0) newBoard[nx][ny] = -1;
                i++;
            }
        }

        backtracking(idx+1, newBoard, cctv);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    answer = n *m;

    vvi board = vvi(n, vector<int>(m, 0));
    vpip cctv;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            if (board[i][j] >= 1 && board[i][j] <= 5) {
                cctv.push_back({board[i][j], {i, j}});
                answer--;
            }

            if (board[i][j] == 6) answer--;
        }
    }

    backtracking(0, board, cctv);

    cout << answer;

    return 0;
}
