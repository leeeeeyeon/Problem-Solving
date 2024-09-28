#include <string>
#include <cmath>
#include <stack>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    stack<int> s;
    for (int i = 0; i < dartResult.size(); i++) {
        // 현재 문자가 알파벳일 경우
        if (isalpha(dartResult[i])) {
            if (dartResult[i] == 'D') { // 제곱
                int score = s.top();
                s.pop();
                s.push(pow(score, 2));
            }
            else if (dartResult[i] == 'T') { // 세제곱
                int score = s.top();
                s.pop();
                s.push(pow(score, 3));
            }
        }
        
        // 현재 문자가 *일 경우, 해당 점수와 직전 점수를 2배로
        else if (dartResult[i] == '*') {
            int curScore = s.top();
            s.pop();

            int prevScore = s.top();
            s.pop();

            s.push(prevScore * 2);
            s.push(curScore * 2);
        }
        
        // 현재 문자가 #일 경우, 현재 점수를 -1배로
        else if (dartResult[i] == '#') {
            int score = s.top();
            s.pop();
            s.push(-score);
        }
        
        else { // 현재 문자가 숫자일 경우
            if (i != 0 && isdigit(dartResult[i-1])) continue;
            string score = "";
            
            for(int j = i; j < dartResult.size(); j++) {
                if (!isdigit(dartResult[j])) break;
                score += dartResult[j];
            }
            
            if (score != "") s.push(stoi(score));
        }
    }
    
    while(!s.empty()) {
        answer += s.top();
        s.pop();
    }
    
    return answer;
}