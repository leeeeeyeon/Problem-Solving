#include <vector>
#include <queue>

#define MAX_NUM 1'000'000

using namespace std;

bool visited[MAX_NUM];

int solution(int x, int y, int n) {
    int answer = 0;
    
    if (x == y) return 0;
    
    // BFS
    queue<pair<int, int>> q; // {수, 연산 횟수}
    q.push({x, 0});
    visited[x] = true;
    
    while(!q.empty()) {
        int elem = q.front().first;
        int cnt = q.front().second;
        
        int one = elem + n;
        int two = elem * 2;
        int three = elem * 3;
        q.pop();
        
        if (one == y || two == y || three == y) return cnt + 1;
        else {
            if (one < y && !visited[one]) {
                q.push({one, cnt + 1});
                visited[one] = true;
            }
            
            if (two < y && !visited[two]) {
                q.push({two, cnt + 1});
                visited[two] = true;
            }
            
            if (three < y && !visited[three]) {
                q.push({three, cnt + 1});
                visited[three] = true;
            }
        }
    }
    
    return -1;
}