#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    // 투 포인터
    int left = 0;
    int right = 0;
    int n = sequence.size();
    
    vector<int> answer = {0, n-1};
    int sum = sequence[0];
    while (left < n && right < n) {        
        // 길이가 짧다 = (right-left)가 작다
        if (sum == k) {
            if (right-left < answer[1]-answer[0]) answer = {left, right};
            else if (right-left == answer[1]-answer[0]) {
                if (left < answer[0]) answer = {left, right};
            }
            
            right++;
            if (right < n) sum += sequence[right];
        }
        
        if (sum > k) { // sum을 줄여야 함 > left를 한 칸 옮긴다
            sum -= sequence[left];
            left++;
        }
        else if (sum < k) { // sum을 키워야 함 > right을 한 칸 옮긴다
            right++;
            if (right < n) sum += sequence[right];
        }
    }
    
    return answer;
}