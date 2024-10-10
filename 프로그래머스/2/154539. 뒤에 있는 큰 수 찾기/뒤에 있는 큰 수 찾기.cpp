#include <vector>
#include <stack>

#define IDX first
#define ELEM second

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer = vector<int>(numbers.size(), -1);
    
    stack<pair<int, int>> s; // {인덱스, 원소}
    
    for (int i = 0; i < numbers.size(); i++) {
        if (s.empty()) s.push({i, numbers[i]});
        else {
            while (!s.empty() && s.top().ELEM < numbers[i]) {
                answer[s.top().IDX] = numbers[i];
                s.pop();
            }
            s.push({i, numbers[i]});
        }
    }
    
    return answer;
}