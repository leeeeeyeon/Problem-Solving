#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

typedef vector<vector<int>> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 도시의 수
    cin >> n;

    int m; // 여행 계획에 속한 도시들의 수
    cin >> m;

    vvi graph = vvi(n+1, vector<int>(n+1, 0));
    vvi dist = vvi(n+1, vector<int>(n+1, INF));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];

            if (i == j) dist[i][j] = 0;
            if (graph[i][j] == 1) dist[i][j] = 1;
        }
    }

    vector<int> plan; // 여행 계획
    for (int i = 0; i < m; i++) {
        int city;
        cin >> city;
        plan.push_back(city);
    }

    // 1. 플로이드-와샬로 정점 사이의 거리를 구해
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // 2. plan을 순회하면서 plan[i] > plan[i+1]이 가능한지 확인
    // 가능하려면 dist[plan[i]][plan[i+1]]이 INF가 아니여야 함
    bool canTravel = true;

    for (int i = 0; i < plan.size()-1; i++) {
        if (dist[plan[i]][plan[i+1]] >= INF) {
            canTravel = false;
            break;
        }
    }

    if (canTravel) cout << "YES";
    else cout << "NO";

    return 0;
}

// N의 최댓값이 200이므로 O(N^3)도 가능
// 다른 사람들은 union-find로 많이 풀었음