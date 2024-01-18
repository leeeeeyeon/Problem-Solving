#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int n, m; // 도시, 버스 노선
int a, b, c; // 시작 도시, 도착 도시, 이동 시간
map<int, vector<pair<int, int>>> graph;

bool bellmanFord(map<int, vector<pair<int, int>>> &graph, vector<long long> &dist, int start) {
    dist[start] = 0;

    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j <= n; ++j) {
            if (graph[j].empty()) continue;

            for (auto node : graph[j]) {
                long long next = dist[j] + node.second;
                if (dist[j] != INF && dist[node.first] > next) dist[node.first] = next;
            }
        }
    }

    for (int j = 1; j <= n; ++j) {
        if (graph[j].empty()) continue;

        for (auto node : graph[j]) {
            long long next = dist[j] + node.second;
            if (dist[node.first] == INF) continue;

            if (dist[node.first] > next) return false;
        }
    }

    return true;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector<long long> dist = vector<long long>(n+1, INF);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    if (bellmanFord(graph, dist, 1)) {
        for (int i = 2; i < dist.size(); ++i) {
            if (dist[i] >= INF) cout << -1 << endl;
            else cout << dist[i] << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}