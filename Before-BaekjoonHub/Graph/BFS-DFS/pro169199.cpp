#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

tuple<int, int, int> slide(tuple<int, int, int> cur, int i, vector<string> &board) {
    int prevCnt = get<2>(cur);

    while (true) {
        int cx, cy, cnt;
        tie(cx, cy, cnt) = cur;

        int nx = cx + dx[i];
        int ny = cy + dy[i];

        // 맨 끝에 부딪힘
        if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size()) return cur;
        // 장애물에 부딪힘
        if (board[nx][ny] == 'D') return cur;

        cur = make_tuple(nx, ny, prevCnt+1);
    }

    return cur;
}

int solution(vector<string> board) {
    int answer = INT_MAX;

    pair<int, int> start;
    pair<int, int> goal;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'R') start = {i, j};
            else if (board[i][j] == 'G') goal = {i, j};
        }
    }

    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

    q.push(make_tuple(start.first, start.second, 0));
    visited[start.first][start.second] = true;

    // BFS
    while(!q.empty()) {
        tuple<int, int, int> cur = q.front();
        q.pop();

        int cx = get<0>(cur);
        int cy = get<1>(cur);
        int cnt = get<2>(cur);

        if (make_pair(cx, cy) == goal) {
            answer = min(answer, cnt);
        }

        // 4 방향으로 장애물이나 끝을 만날 때까지 쭉 이동했을 때 나오는 좌표를 담아
        for (int i = 0; i < 4; i++) {
            tuple<int, int, int> nxt = slide(cur, i, board);

            int nx = get<0>(nxt);
            int ny = get<1>(nxt);

            if (nxt == cur) continue;
            if (visited[nx][ny]) continue;

            q.push(nxt);
            visited[nx][ny] = true;
        }
    }

    if (answer == INT_MAX) return -1;

    return answer;
}