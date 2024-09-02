#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;
typedef vector<vector<pair<int, int>>> vvpii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; // 노드의 개수, 간선의 개수
    cin >> n >> m;

    vvpii graph = vvpii(n+1);
    for (int i = 0; i < m; i++ ) {
        int a, b, c; // 노드 A, 노드 B, A-B 사이 간선의 길이
        cin >> a >> b >> c;
        graph[a].push_back({b, c}); // {노드, 간선의 길이}
        graph[b].push_back({a, c});

        // 두 개의 헛간은 하나 이상의 길로 연결될 수 있음
    }

    // 특정 노드 사이의 거리만 구하면 되므로 다익스트라 알고리즘 사용
    vector<ll> distance = vector<ll>(n+1, LLONG_MAX);
    priority_queue<pair<ll, int>> pq; // {거리, 노드}

    pq.push({0, 1});
    distance[1] = 0;

    while(!pq.empty()) {
        ll curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        // 인접 노드 탐색
        for (auto elem : graph[curNode]) {
            // 만약 해당 노드의 distance 값이 현재 노드를 지나는거보다 작으면 pass
            ll nextNode = elem.first;
            ll newDist = curDist + elem.second;
            if (distance[nextNode] <= newDist) continue;

            distance[nextNode] = newDist;
            pq.push({-newDist, nextNode});
        }
    }

    cout << distance[n];

    return 0;
}
