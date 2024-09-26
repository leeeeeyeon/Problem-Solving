#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 바뀌지 않고 그대로인 문자열이라면 true 반환
bool isNumber(string s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    
    return true;
}

int solution(string s) {    
    // 알파벳이 없을 경우 원래 문자열을 int 변환 후 return
    if (isNumber(s)) return stoi(s);
    
    string answer = "";
    
    vector<string> words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    unordered_map<string, string> um; // 영단어에 대응되는 숫자
    
    for (int i = 0; i < words.size(); i++) {
        um[words[i]] = to_string(i);
    }
    
    for (int i = 0; i < s.size(); i++) {
        // 숫자인 경우 answer에 그대로 추가
        if (!isalpha(s[i])) answer += s[i];
        else { // 알파벳인 경우
            // one ~ nine 사이의 단어가 나올 때까지 temp에 문자열을 더해
            string temp = "";
            
            while(isalpha(s[i])) {
                temp += s[i];
                
                 if (find(words.begin(), words.end(), temp) != words.end()) {
                     answer += um[temp];
                     break;
                 }
                
                i++;
            }
        }
    }
    
    return stoi(answer);
}