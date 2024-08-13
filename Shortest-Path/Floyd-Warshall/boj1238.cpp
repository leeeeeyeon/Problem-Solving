#include <iostream>
#include <algorithm>

#define MAX_N 1'000
#define INF 987654321

using namespace std;

int dist[MAX_N+1][MAX_N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x; // 학생 수, 도로의 개수, 파티를 하는 마을
    cin >> n >> m >> x;

    // 1. dist 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    int start, end, cost; // 도로 시작점, 끝점, 소요 시간
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> cost;
        dist[start][end] = cost;
    }

    // 2. 플로이드 와샬
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    // 3. 1번부터 N번 마을까지 i > x > i를 구해서 mx 갱신
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i][x] >= INF || dist[x][i] >= INF) continue;

        mx = max(mx, dist[i][x] + dist[x][i]);
    }

    cout << mx;

    return 0;
}

// 피드백: 플로이드 와샬로 풀었지만 원래 의도는 '다익스트라'
// 플로이드 와샬은 약 900ms, 다익스트라는 약 4ms로 다익스트라 사용하는 것이 더 최적화된 풀이
// 출처: https://bbeomgeun.tistory.com/85