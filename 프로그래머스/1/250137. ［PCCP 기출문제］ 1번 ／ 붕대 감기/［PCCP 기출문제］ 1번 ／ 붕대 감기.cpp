#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> vvi;

int findMaxTime(vvi attacks) {
    int result = 0;
    for (auto attack : attacks) {
        result = max(result, attack[0]);
    }
    
    return result;
}

int solution(vector<int> bandage, int health, vvi attacks) {
    int curHealth = health; // 현재 체력
    
    int maxTime = findMaxTime(attacks);
    
    int cnt = 0; // 연속 성공 횟수
    int idx = 0; // attacks의 몇 번째 공격을 할 차례인지
    for (int t = 1; t <= maxTime; t++) {
        // 몬스터의 공격이 들어온 경우
        if (idx < attacks.size() && attacks[idx][0] == t) {
            // cnt를 0으로 초기화
            cnt = 0;
            
            // curHealth에서 몬스터의 공격만큼 감소
            curHealth -= attacks[idx][1];
            
            // 만약 curHealth가 0 이하가 되어 죽는다면 -1 반환
            if (curHealth <= 0) return -1;
            
            idx++;
        } else { // 몬스터의 공격이 들어오지 않은 경우
            cnt++;
            
            // 기술 성공 시 추가 체력 획득
            if (cnt == bandage[0]) {
                curHealth = min(health, curHealth + bandage[1] + bandage[2]);
                cnt = 0;
            } else {
                curHealth = min(health, curHealth + bandage[1]);
            }
                            
        }
    }
    
    
    return curHealth;
}