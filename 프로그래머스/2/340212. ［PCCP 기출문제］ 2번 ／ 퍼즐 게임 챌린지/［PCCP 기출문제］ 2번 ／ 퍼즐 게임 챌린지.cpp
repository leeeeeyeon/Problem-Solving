#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int solution(vector<int> diffs, vector<int> times, ll limit) {
    // 이분 탐색
    int start = 1;
    int end = *max_element(diffs.begin(), diffs.end());
    
    int answer = end; // 제한 시간 내 퍼즐을 해결하기 위한 숙련도의 최솟값
    
    while (start <= end) {
        // 현재 숙련도
        int mid = (start + end) / 2;
        
        ll sum = 0;
        for (int i = 0; i < diffs.size(); i++) {
            int diff = diffs[i];
            int timeCur = times[i];
            
            if (diff <= mid) {
                sum += timeCur;
            } else { // diff > mid
                int timePrev;
                if (i >= 1) timePrev = times[i-1];
                else timePrev = 0;
                
                sum += (timeCur + timePrev) * (diff - mid) + timeCur;
            }
        }
        
        if (sum <= limit) { // 제한시간 안에 해결, 숙련도를 최소로 만들어보자
            answer = min(answer, mid);
            end = mid - 1;
        } else { // sum > limit, 제한시간을 초과한 경우 숙련도를 높여야 함
            start = mid + 1;
        }
    }
    
    return answer;
}