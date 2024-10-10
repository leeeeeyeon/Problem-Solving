#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int, int> cheolsu; // 철수가 먹는 토핑 종류별 갯수
    unordered_map<int, int> brother; // 동생이 먹는 토핑 종류별 갯수
    
    // 철수: {}
    // 동생: {topping}
    // 인 채로 시작
    for (int t : topping) {
        brother[t]++;
    }
    
    for (int i = 0; i < topping.size(); i++) {
        int t = topping[i];
        cheolsu[t]++;
        brother[t]--;
        if (brother[t] == 0) brother.erase(t);
        
        if (cheolsu.size() == brother.size()) answer++;
    }
    
    return answer;
}