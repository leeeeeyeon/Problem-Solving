#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    unordered_map<int, int> um;
    
    // 문자열 s에서 숫자를 적절히 추출하여 set에 담는다
    string numStr;
    for (int i = 2; i < s.size()-1; i++) {
        // 만약 이전 글자가 '{', ','라면 numStr 시작
        if (s[i-1] == '{' || s[i-1] == ',') numStr = s[i];
        
        // 만약 다음 글자가 ',' 또는 '}'라면 numStr 끝
        // numStr를 자연수로 변환 후 map에 삽입
        else if (s[i] == '}' || s[i] == ',') {
            if (numStr != "") um[stoi(numStr)]++;
            numStr = "";
        }
        
        else {
            numStr += s[i];
        }
    }
    
    // map을 정렬한 후 vector로 변환
    vector<pair<int, int>> arr(um.begin(), um.end());
    sort(arr.begin(), arr.end(), cmp);
    
    // 튜플에서 가장 빈번하게 나온 순으로 구성
    for (auto elem : arr) answer.push_back(elem.first);
    
    return answer;
}