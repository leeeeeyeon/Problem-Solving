#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    for (int work : works) pq.push(work);
    
    while (n > 0) {
        if (pq.top() == 0) break;
        
        int newWork = pq.top()-1;
        n--;
        pq.pop();
        
        pq.push(newWork);
    }
    
    while(!pq.empty()) {
        int elem = pq.top();
        answer += (elem * elem);
        
        pq.pop();
    }
    
    return answer;
}