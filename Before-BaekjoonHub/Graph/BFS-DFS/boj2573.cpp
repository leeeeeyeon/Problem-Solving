#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cx, cy, nx, ny;

int countGroup(vector<vector<int>> &board, vector<pair<int, int>> iceberg, vector<bool> &melt) {
    int group = 0;

    vector<vector<int>> visited = vector(n, vector<int>(m));

    for (int i = 0; i < iceberg.size(); ++i) {
        pair<int, int> ice = iceberg[i];

        if (melt[i]) continue;
        if (visited[ice.X][ice.Y]) continue;

        stack<pair<int, int>> s;
        s.push({ice.X, ice.Y});
        visited[ice.X][ice.Y] = true;

        while (!s.empty()) {
            cx = s.top().X;
            cy = s.top().Y;
            s.pop();

            for (int i = 0; i < 4; ++i) {
                nx = cx + dx[i];
                ny = cy + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (board[nx][ny] == 0 || visited[nx][ny]) continue;
                s.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
        group++;
    }

    return group;
}

bool allMelt(vector<bool> &melt) {
    for (auto elem : melt) {
        if (!elem) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector<vector<int>> board = vector(n, vector<int>(m));
    vector<pair<int, int>> iceberg;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];

            if (board[i][j] != 0) iceberg.push_back({i, j});
        }
    }
    vector<bool> melt = vector<bool>(iceberg.size());

    int time = 0;
    while (countGroup(board, iceberg, melt) == 1 && !allMelt(melt)) {
        map<pair<int, int>, int> mp;
        for (int i = 0; i < iceberg.size(); ++i) {
            // 한번에 줄어드는 것이기 때문에 앞선 빙산이 0이 된 것이 다음 빙산에 영향을 미치지 않도록 주의하기
            pair<int, int> ice = iceberg[i];
            if (melt[i]) continue;

            int cnt = 0;

            cx = ice.X;
            cy = ice.Y;
            for (int k = 0; k < 4; ++k) {
                nx = cx + dx[k];
                ny = cy + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (board[nx][ny] == 0) cnt ++;
            }

            mp[{cx, cy}] = cnt;
        }

        // mp에 줄어들 양을 저장하고 한번에 줄어들도록 함
        for (auto elem : mp) {
            board[elem.first.X][elem.first.Y] -= mp[{elem.first.X, elem.first.Y}];
            if (board[elem.first.X][elem.first.Y] < 0) board[elem.first.X][elem.first.Y] = 0;
        }
        // 높이가 0이 되면 빙산 vector에서 삭제
        for (int i = 0; i < iceberg.size(); ++i) {
            if (board[iceberg[i].X][iceberg[i].Y] == 0) melt[i] = true;
        }

        time++;
    }

    if (countGroup(board, iceberg, melt) > 1) cout << time << "\n";
    else cout << 0 << "\n";

    return 0;
}