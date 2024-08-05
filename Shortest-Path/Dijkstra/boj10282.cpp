#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int t; // 테스트 케이스의 개수
int n, d, c; // 컴퓨터 개수, 의존성 개수, 해킹당한 컴퓨터의 번호
int a, b, s; // a가 b를 의존하며, b가 감염되면 s초 후 a도 감염된다
int dist, now, cost; // 다익스트라 알고리즘을 구현하며 사용할 변수

void dijkstra(map<int, vector<pair<int, int>>> &mp, vector<int> &distance, int start) {
    // 우선순위 큐를 활용
    // 작은 값이 우선이 되도록 greater를 사용
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // 시작 노드 삽입
    pq.push({0, start}); // 거리, 노드 순
    // 시작 노드에 대한 최단거리는 0으로 초기화
    distance[c] = 0;

    while (!pq.empty()) {
        dist = pq.top().first;
        now = pq.top().second;
        pq.pop();

        // 이미 방문한 노드라면 skip
        if (dist < distance[now]) continue;
        // 인접 노드에 대해 최단 거리를 갱신
        for (auto elem : mp[now]) {
            cost = dist + elem.second;
            if (cost < distance[elem.first]) {
                pq.push({cost, elem.first});
                distance[elem.first] = cost;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> d >> c;

        // 노드 간의 거리를 저장하는 인접 행렬
        map<int, vector<pair<int, int>>> mp;
        // 최단 거리를 저장
        vector<int> distance(n+1, INF);

        // 의존 정보 입력 받음
        while (d--) {
            cin >> a >> b >> s;
            mp[b].push_back({a, s}); // 노드, 간선
        }

        // 다익스트라 알고리즘을 사용하여 최단 거리 계산
        dijkstra(mp, distance, c);

        int cnt = 0;
        int ret = 0;
        // 총 감염되는 컴퓨터 수와 마지막 컴퓨터가 감염되기까지 걸리는 시간 계산
        for (int i = 1; i <= n; ++i) {
            if (distance[i] != INF) {
                cnt++;
                if (distance[i] > ret) ret = distance[i];
            }
        }

        cout << cnt << " " << ret << "\n";
    }

    return 0;
}