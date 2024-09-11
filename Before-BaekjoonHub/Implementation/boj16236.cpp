#include <bits/stdc++.h>

using namespace std;

#define BABY_SHARK 9
#define X first
#define Y second
#define INF 987654321

struct Shark {
    pair<int, int> point; // 좌표
    int cnt = 0; // 먹은 물고기 수
    int size = 2; // 아기 상어의 크기
};

struct Fish {
    int dist = INF; // 아기 상어와의 거리
    int size = 0; // 크기
    pair<int, int> point;

    Fish(int d, int s, int x, int y) {
        this->dist = d;
        this->size = s;
        this->point = {x, y};
    }
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(vector<vector<int>> &board, vector<Fish> &fishes, Shark &shark) {
    for (int i = 0; i < fishes.size(); ++i) {
        // 아기 상어보다 큰 물고기는 먹을 수 없음 > dist = INF
        if (fishes[i].size >= shark.size) {
            fishes[i].dist = INF;
            continue;
        }

        queue<pair<int, pair<int, int>>> q; // { {거리, 좌표}, {거리, 좌표} ....}
        vector<vector<int>> visited = vector<vector<int>>(board.size(), vector<int>(board.size(), false));

        // 초기화
        auto goal = fishes[i].point;
        q.push({0, shark.point});
        visited[shark.point.X][shark.point.Y] = true;

        // BFS
        while (!q.empty()) {
            int dist = q.front().first;
            int cx = q.front().second.X;
            int cy = q.front().second.Y;
            q.pop();

            if (goal == make_pair(cx, cy)) {
                fishes[i].dist = dist;
                break;
            }

            for (int j = 0; j < 4; ++j) {
                int nx = cx + dx[j];
                int ny = cy + dy[j];

                // Out of Bounds
                if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board.size()) continue;
                // 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없다
                if (board[nx][ny] > shark.size) continue;
                // 이미 방문한 경우
                if (visited[nx][ny]) continue;

                q.push({dist+1, make_pair(nx, ny)});
                visited[nx][ny] = true;
            }
        }
    }
}

bool canEat(vector<Fish> &fishes, Shark shark) {
    for (auto fish : fishes) {
        if (fish.size < shark.size) return true;
    }

    return false;
}

// 가장 거리가 가까운 물고기 > 가장 위(x좌표가 작을수록) > 가장 왼쪽 (y좌표가 작을수록)
bool compare(Fish a, Fish b) {
    if (a.dist < b.dist) return true;
    else if (a.dist == b.dist && a.point.X < b.point.X) return true;
    else if (a.dist == b.dist && a.point.X == b.point.X) return a.point.Y < b.point.Y;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 공간의 크기 (최대 20)
    cin >> n;

    vector<vector<int>> board = vector<vector<int>>(n, vector<int>(n, 0));
    vector<Fish> fishes;
    Shark shark;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];

            // 아기 상어의 위치
            if (board[i][j] == BABY_SHARK) {
                shark.point = {i, j};
                shark.cnt = 0;
                board[i][j] = 0;
            }

            // 물고기의 위치
            if (board[i][j] >= 1 && board[i][j] <= 6) {
                Fish fish = Fish(INF, board[i][j], i, j);
                fishes.push_back(fish);
            }
        }
    }

    // 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지
    // = 더 이상 먹을 수 있는 물고기가 공간에 없다면 프로그램 종료
    // 가장 거리가 가까운 물고기 > 가장 위(x좌표가 작을수록) > 가장 왼쪽 (y좌표가 작을수록)
    // 물고기는 최대 399개
    int ret = 0; // 걸리는 시간

    // 시작점과 물고기들 사이의 거리를 구한다
    bfs(board, fishes, shark);

    // 1. fishes를 순회하며 BFS로 dist 갱신 (fish.size >= shark.size일 경우 dist=-1)
    // 3. 만약 fish.size >= shark.size라면 while문 탈출
    // 4. 그렇지 않다면 fishes[0]을 먹고, 그 자리로 이동
    while(true) {
        // 물고기가 공간에 없을 경우
        if (fishes.empty()) break;
        // 물고기는 있는데 모두 아기 상어보다 클 경우
        if (!canEat(fishes, shark)) break;

        bfs(board, fishes, shark);
        sort(fishes.begin(), fishes.end(), compare);

        Fish target = fishes[0];
        if (target.dist == INF) break;

        ret += target.dist; // 걸리는 시간 더함
        shark.point = target.point; // 상어의 좌표 이동
        // 자신의 크기와 같은 수의 물고기를 먹으면 크기 1 증가
        shark.cnt++;
        if (shark.cnt == shark.size) {
            shark.size++;
            shark.cnt = 0;
        }
        board[target.point.X][target.point.Y] = 0; // 물고기 사라짐
        fishes.erase(fishes.begin()); // 물고기 사라짐
    }

    cout << ret << "\n";
}