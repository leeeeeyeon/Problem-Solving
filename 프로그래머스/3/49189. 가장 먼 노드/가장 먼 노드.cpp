#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

int solution(int n, vvi edge) {
    int answer = 0;
    
    // edge를 기반으로 인접 그래프를 만들어
    vvi graph = vvi(n+1);
    for (auto elem : edge) {
        graph[elem[0]].push_back(elem[1]);
        graph[elem[1]].push_back(elem[0]);
    }
    
    // 다익스트라 알고리즘으로 1번 노드부터 모든 노드까지의 거리(distance)를 구해
    vector<int> distance = vector<int>(n+1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    distance[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        
        int newDist = curDist + 1;
        for (auto nextNode : graph[curNode]) {
            // 인접 노드의 최단 거리가 현재 노드를 경유하는 것보다 짧은 경우 pass
            if (distance[nextNode] > newDist) {
                distance[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }
    
    // distance에서 가장 큰 값을 가진 원소의 개수 count
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        if (distance[i] > mx) {
            answer = 1;
            mx = distance[i];
            continue;
        }
        
        if (distance[i] == mx) answer++;
    }
    
    return answer;
}