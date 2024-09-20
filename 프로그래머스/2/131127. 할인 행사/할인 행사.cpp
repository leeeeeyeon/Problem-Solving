#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool getAllDiscount(unordered_map<string, int> jh, unordered_map<string, int> mart) {
    // 정현이가 원하는 제품 중 하나라도 할인하지 않는다면 false
    for (auto elem : jh) {
        string product = elem.first;
        
        if (mart[product] < elem.second) return false;
    }
    
    return true;
}


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    // 누적합 알고리즘 응용
    unordered_map<string, int> jh;
    unordered_map<string, int> mart;
        
    // 정현이의 요구사항을 um으로 만들어
    for (int i = 0; i < want.size(); i++) {
        jh[want[i]] = number[i];
    }
    
    // 첫째 날은 mart에 다 넣고 
    for (int i = 0; i < 10; i++) {
        mart[discount[i]]++;
    }
    // 요구사항 충족하는지 확인
    if (getAllDiscount(jh, mart)) answer++;
        
    // 둘째 날부터는 이전 원소 빼고, 다음 원소 넣어
    for (int i = 1; i <= discount.size()-10; i++) {
        mart[discount[i-1]]--;
        mart[discount[i+9]]++;
        
        // 요구사항 충족하는지 확인
        if (getAllDiscount(jh, mart)) answer++;
    }
    
    return answer;
}