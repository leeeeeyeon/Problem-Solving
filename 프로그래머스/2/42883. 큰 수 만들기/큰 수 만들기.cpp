#include <string>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    stack<char> s;
    int cnt = k;
    for (char c : number) {
        if (s.empty()) s.push(c);
        else {
            // top이 c보다 작다면 ...
            while (!s.empty() && s.top() < c) {
                if (cnt == 0) break;
                s.pop();
                cnt--;
            }
            s.push(c); // TC 4에서 하면 안됨 ...
        }
    }
    
    while (s.size() > number.size() - k) s.pop();
    
    while (!s.empty()) {
        answer = s.top() + answer;
        s.pop();
    }
    
    return answer;
}