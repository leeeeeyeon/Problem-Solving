#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (s / n == 0) return { -1 };
    
    if (s % n == 0) {
        answer = vector<int>(n, s/n);
    } else {
        answer = vector<int>(n-s%n, s/n);
        
        while (answer.size() < n) answer.push_back(s/n+1);
    }
    
    return answer;
}

// 1트) 재귀로 완탐 > 시간 초과
// 2트) https://school.programmers.co.kr/questions/71284 참고
