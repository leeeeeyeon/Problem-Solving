#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isOpening(char c) {
    if (c == '(' || c == '{' || c == '[') return true;
    else return false;
}

char correspondOpening(char c) {
    if (c == ')') return '(';
    else if (c == '}') return '{';
    else return '[';
}

// 올바른 괄호 문자열인지 확인하는 함수
bool isRightString(string str) {
    stack<char> s;
    
    for (char c : str) {
        // 여는 괄호일 경우 스택에 삽입
        if (isOpening(c)) s.push(c);
        else { // 닫는 괄호일 경우
            if (s.empty()) return false;
            
            // 여는 괄호가 나올 때까지 pop
            // 만약 쌍이 아닌 괄호를 만났을 경우 더 이상 pop 불가
            if (s.top() == correspondOpening(c)) s.pop();
            else break;
        }
    }
    
    if (s.empty()) return true;
    else return false;
}

int solution(string s) {
    int answer = 0;
    
    int length = s.size();
    
    // 문자열을 뒤에 붙여서 회전처럼 구현
    s += s;
    
    // 올바른 괄호 문자열이라면 answer에 1을 더한다
    for (int i = 0; i < length; i++) {
        if (isRightString(s.substr(i, length))) answer++;
    }
    
    return answer;
}