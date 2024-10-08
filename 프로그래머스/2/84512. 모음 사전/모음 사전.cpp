#include <string>

using namespace std;

int cnt, answer;

string alphabets = "AEIOU";

void dfs(string target, string s) {
    cnt++;
    
    if (s == target) {
        answer = cnt-1;
        return;
    }
    
    if (s.size() >= 5) return;
    
    for (int i = 0; i < alphabets.size(); i++) {
        dfs(target, s + alphabets[i]);
    }
    
    return;
}


int solution(string word) {
    dfs(word, "");
    
    return answer;
}

// 참고) https://cherishvert.tistory.com/83
