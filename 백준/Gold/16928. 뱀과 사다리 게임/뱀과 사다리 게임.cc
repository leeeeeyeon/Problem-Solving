#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int n, m; // 사다리의 수, 뱀의 수
    cin >> n >> m;

    vector<pair<bool, int>> ladders = vector<pair<bool, int>>(101, {false, 0}); // {사다리 칸 여부, 이동하는 칸}
    vector<pair<bool, int>> snakes = vector<pair<bool, int>>(101, {false, 0}); // {뱀 칸 여부, 이동하는 칸}
    
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ladders[x] = {true, y};
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        ladders[u] = {true, v};
    }

    // BFS
    queue<pair<int, int>> q; // {칸 위치, 주사위 굴린 횟수}
    vector<int> visited = vector<int>(101, 100);

    // 초기화
    for (int i = 2; i <= 7; i++) {
        bool isLadder = ladders[i].first;
        int target = isLadder ? ladders[i].second : i;

        q.push({target, 1});
        visited[target] = 1;
    }

    int answer = 100;
    while (!q.empty()) {
        int point = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (point == 100) {
            if (cnt < answer) answer = cnt;
            continue;
        }

        for (int i = 1; i <= 6; i++) {
            int nextPoint = point + i;
            if (nextPoint > 100) break;

            // 지금 칸에서 주사위를 i칸 굴려서 다음 칸 가는 게 이득인 경우
            if (cnt+1 < visited[nextPoint]) {
                bool isLadder = ladders[nextPoint].first;
                bool isSnake = snakes[nextPoint].first;

                if (!isLadder && !isSnake) {
                    q.push({nextPoint, cnt+1});
                    visited[nextPoint] = cnt+1;
                } else { // nextPoint가 사다리 또는 뱀 칸인 경우
                    int dest = isLadder ? ladders[nextPoint].second : snakes[nextPoint].second;

                    if (cnt+1 < visited[dest]) {
                        q.push({dest, cnt+1});
                        visited[dest] = cnt+1;
                    }
                }
            }
        }
    }

    cout << answer;

    return 0;
}
