#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> belt;
    stack<int> subBelt;
    vector<bool> isInBelt = vector<bool>(order.size()+1, false);
    
    // 컨테이너 벨트 초기화
    for (int i = order.size(); i > 0; i--) {
        belt.push(i);
        isInBelt[i] = true;
    }
    
    for (int i = 0; i < order.size(); i++) {
        int elem = order[i];
        
        if (isInBelt[elem]) {
            while (belt.top() != elem) {
                subBelt.push(belt.top());
                isInBelt[belt.top()] = false;
                
                belt.pop();
            }
            
            answer++;
            belt.pop();
        } else {
            if (subBelt.top() == elem) {
                answer++;
                subBelt.pop();
            } else {
                break;
            }
        }
    }
    
    return answer;
}