#include <bits/stdc++.h>

using namespace std;

#define INF 9876543421

map<int, vector<int>> mp;
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, x; // 도시의 개수, 도로의 개수, 거리 정보, 출발 도시
    cin >> n >> m >> k >> x;

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        mp[a].push_back(b);
    }

    dist = vector<int>(n+1, INF);
    pq.push({0, x});
    dist[x] = 0;

    int d, now, cost;
    while (!pq.empty()) {
        d = pq.top().first;
        now = pq.top().second;
        pq.pop();

        if (dist[now] < d) continue;
        for (auto elem : mp[now]) {
            cost = d + 1;
            if (cost < dist[elem]) {
                dist[elem] = cost;
                pq.push({cost, elem});
            }
        }
    }

    vector<int> ret;
    for (int i = 1; i < dist.size(); ++i) {
        if (dist[i] == k) ret.push_back(i);
    }

    if (ret.empty()) cout << -1 << "\n";
    else {
        for (auto elem : ret) {
            cout << elem << "\n";
        }
    }

    return 0;
}