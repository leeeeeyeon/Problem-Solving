#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    unordered_map<string, int> um;
    
    // 길이가 1인 모든 단어(A-Z)를 포함하도록 사전 초기화
    int idx = 1;
    for (int i = 0; i < 26; i++) {
        string temp = "";
        temp += 'A' + i;
        um[temp] = idx;
        idx++;
    }
    
    for (int i = 0; i < msg.size(); i++) {
        // 마지막 글자
        if (i == msg.size()-1) {
            string lastChar = "";
            lastChar += msg[i];
            answer.push_back(um[lastChar]);
            continue;
        } else {
            string temp = ""; // 현재 입력
            temp += msg[i];
            while (um[temp] != 0) {
                temp += msg[i+1];
                i++;
            }
            
            // answer에 현재 입력과 일치하는 가장 긴 문자열 w 추가
            string w = temp.substr(0, temp.size()-1);
            answer.push_back(um[w]);
            
            // w+(다음 글자)에 해당하는 단어를 사전에 등록
            um[temp] = idx;
            idx++;
            
            i--;
        }
    }
    
    return answer;
}