#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    stack<int> s;
    for (auto elem : arr) {
        if (s.empty() || s.top() != elem) s.push(elem);
    }
    
    while (!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }
    
    reverse(answer.begin(), answer.end());

    return answer;
}