#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    // vector를 queue로 만들어
    // {원소, 원래 큐 번호, 큐에서의 위치}
    queue<tuple<int, int, int>> q1;
    queue<tuple<int, int, int>> q2;
    
    for (int i = 0; i < queue1.size(); i++) q1.push(make_tuple(queue1[i], 1, i));
    for (int i = 0; i < queue2.size(); i++) q2.push(make_tuple(queue2[i], 2, i));
    
    // 두 큐에 담긴 모든 원소의 합 계산
    ll sum = 0;
    ll q1Sum = 0;
    ll q2Sum = 0;
    for (auto elem : queue1) {
        sum += elem;
        q1Sum += elem;
    }
    for (auto elem : queue2) {
        sum += elem;
        q2Sum += elem;
    }
    
    // 각 큐의 원소 합
    ll target = sum / 2;
    
    // target 이상인 원소가 있을 경우, 각 큐의 원소 합을 같게 만들 수 없음
    for (auto elem : queue1) {
        if (elem > target) return -1;
    }
    for (auto elem : queue2) {
        if (elem > target) return -1;
    }
    
    // sum이 홀수일 경우, 각 큐의 원소 합을 같게 만들 수 없음
    if (sum % 2 != 0) return -1;
    
    // 두 큐의 합이 같을 때까지 while문 반복
    int cnt1 = 0;
    int cnt2 = 0;
    while(q1Sum != q2Sum) {        
        // sum이 더 큰 쪽에서 더 작은 쪽으로 원소를 옮기고, sum 갱신
        if (q1Sum > q2Sum) { // q1에서 q2로 옮긴다
            // 원소가 제자리로 돌아왔을 경우, 무한 루프를 돈다는 의미
            if (q1.front() == make_tuple(queue1[0], 1, 0)) {
                cnt1++;
                if (cnt1 == 2) return -1;
            }
            
            q2.push(q1.front());
            q2Sum += get<0>(q1.front());
            q1Sum -= get<0>(q1.front());
            
            q1.pop();
        } else { // q2에서 q1으로 옮긴다
            // 원소가 제자리로 돌아왔을 경우, 무한 루프를 돈다는 의미
            if (q2.front() == make_tuple(queue2[0], 2, 0)) {
                cnt2++;
                if (cnt2 == 2) return -1;
            }
            q1.push(q2.front());
            q1Sum += get<0>(q2.front());
            q2Sum -= get<0>(q2.front());
            
            q2.pop();
        }
        
        // 작업 횟수 +1
        answer++;
    }
    
    return answer;
}