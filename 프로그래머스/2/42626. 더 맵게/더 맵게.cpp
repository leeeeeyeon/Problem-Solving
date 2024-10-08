#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int elem : scoville) pq.push(elem);
    
    // 더 이상 섞을 수 없을 때까지
    while (pq.size() != 1) {
        if (pq.top() >= K) break;
        
        int first = pq.top();
        pq.pop();
        
        int second = pq.top();
        pq.pop();
        
        pq.push(first + second * 2);
        answer++;
    }
    
    if (pq.top() < K) return -1;
    else return answer;
}