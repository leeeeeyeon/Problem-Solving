#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> um;

// um 값이 더 큰 문자 선택, 같으면 사전 순으로 빠른 것 선택
char chooseChar(char a, char b) {
    if (um[a] == um[b]) {
        if (a < b) return a;
        else return b;
    }
    
    if (um[a] > um[b]) return a;
    else return b;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] < 4) { // 비동의
            // 첫 번째 캐릭터의 점수 추가
            um[survey[i][0]] += (4-choices[i]);
        } else if (choices[i] > 4) { // 동의
            // 두 번째 캐릭터의 점수 추가
            um[survey[i][1]] += (choices[i]-4);
        }
    }
    
    // um을 기반으로 성격 유형 계산
    answer += chooseChar('R', 'T');
    answer += chooseChar('C', 'F');
    answer += chooseChar('J', 'M');
    answer += chooseChar('A', 'N');
    
    return answer;
}