#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(int n) {
    vvi board = vvi(n, vector<int>(n, 0));
    vvi distance = vvi(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // 다익스트라
    // 인접한 방문하지 않은 노드 중에서 가장 작은 노드 선택 (우선순위 큐)
    // 해당 노드까지의 최단 거리 갱신
    priority_queue<pair<int, pii>> pq;
    distance[0][0] = board[0][0];
    pq.push({-distance[0][0], {0, 0}});

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        pq.pop();

        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            int newDist = min(distance[nx][ny], dist + board[nx][ny]);
            // visited 대신 distance[i][j]가 newDist보다 작으면 방문처리
            if (distance[nx][ny] <= newDist) continue;

            pq.push({-newDist, {nx, ny}});
            distance[nx][ny] = newDist;
        }
    }

    return distance[n-1][n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int p = 1;
    while (true) {
        cin >> n;

        // N = 0이 입력으로 주어지면 전체 입력 종료
        if (n == 0) break;

        // 링크가 잃는 최소 금액
        int mn = solution(n);

        cout << "Problem " << p++ << ": " << mn << '\n';
    }

    return 0;
}

// 격자판 위에서 다익스트라를 할 때 인접 그래프를 만들어줄 필요 없음