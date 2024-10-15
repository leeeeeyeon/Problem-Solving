#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<string>> graph;
unordered_map<string, int> ticketCnt;
unordered_map<string, int> visited;
vector<vector<string>> routes;

bool allVisited() {    
    for (auto elem : ticketCnt) {
        string str = elem.first;
        int cnt = elem.second;
        if (cnt != visited[str]) return false;
    }
    
    return true;
}

void dfs(string curNode, vector<string> &route) {
    // 재귀 탈출 조건) 모든 티켓을 사용
    if (allVisited()) {        
        routes.push_back(route);

        return;
    }
    
    for (string elem : graph[curNode]) {        
        string temp = curNode + elem;
        
        if (visited[temp] == ticketCnt[temp]) continue;
        
        route.push_back(elem);
        visited[temp]++;
        
        dfs(elem, route);
        
        route.pop_back();
        visited[temp]--;
    }
}

vector<string> solution(vector<vector<string>> tickets) {    
    for (auto ticket : tickets) {
        // 인접 그래프 생성
        graph[ticket[0]].push_back(ticket[1]);
        
        // 방문 여부 초기화
        string temp = ticket[0] + ticket[1];
        ticketCnt[temp]++;
    }
    
    // DFS
    vector<string> route = {"ICN"};
    dfs("ICN", route);
    
    // 가능한 경로가 여러 개일 경우 알파벳 순서가 앞서는 경로 return
    if (routes.size() == 0) return {"TEST"};
    if (routes.size() == 1) return routes[0];
    else {
        sort(routes.begin(), routes.end());
        return routes[0];
    }
}

// 피드백) A > B 티켓이 여러 개 있을 수 있음
