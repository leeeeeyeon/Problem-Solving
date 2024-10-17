#include <vector>
#include <climits>
#include <queue>

#define DIST first
#define NODE second

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;
typedef vector<vector<pii>> vvpii;

int solution(int N, vvi roads, int K) {
    int answer = 0;
    
    // 인접 그래프 초기화
    vvpii graph = vvpii(N+1); // {거리, 노드}
    for (auto road : roads) {
        graph[road[0]].push_back({road[2], road[1]});
        graph[road[1]].push_back({road[2], road[0]});
    }
    
    vector<int> distance = vector<int>(N+1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    pq.push({0, 1});
    distance[1] = 0;
    
    while (!pq.empty()) {
        int curDist = pq.top().DIST;
        int curNode = pq.top().NODE;
        pq.pop();
        
        for (auto elem : graph[curNode]) {
            int nextDist = curDist + elem.DIST;
            int nextNode = elem.NODE;
            
            // curNode를 들리는 것보다 현재 경로가 더 짧거나 같을 때
            if (distance[elem.NODE] <= nextDist) continue;
            
            distance[elem.NODE] = nextDist;
            pq.push({nextDist, elem.NODE});
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (distance[i] <= K) answer++;
    }

    return answer;
}