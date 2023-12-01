#include <bits/stdc++.h>

using namespace std;

int t; // 테스트 케이스
int q; // 적용할 연산의 개수
char a; // 연산: D 또는 I
int b; // 정수

priority_queue<int> pq1; // 큰 값 우선
priority_queue<int> pq2; // 작은 값 우선
map<int, int> mp; // 이중 우선순위 큐에 해당 원소가 몇 개 있는지

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        // 테스트 케이스마다 비워주어야 함
        priority_queue<int, vector<int>, less<>> pq1; // 큰 값 우선
        priority_queue<int, vector<int>, greater<>> pq2; // 작은 값 우선
        map<int, int> mp;

        cin >> q;
        while (q--) {
            cin >> a >> b;
            if (a == 'I') { // 삽입
                pq1.push(b);
                pq2.push(b);
                mp[b] ++;
            } else if (a == 'D') { // 삭제
                if (b == 1) { // 최댓값을 삭제
                    if (pq1.empty()) continue;
                    mp[pq1.top()] --;
                    pq1.pop();
                } else if (b == -1) { // 최솟값을 삭제
                    if (pq2.empty()) continue;
                    mp[pq2.top()] --;
                    pq2.pop();
                }

                // 반대 큐에서 삭제된 값이 top에 남아있지 않도록 정리
                while (!pq1.empty() && mp[pq1.top()] == 0) pq1.pop();
                while (!pq2.empty() && mp[pq2.top()] == 0) pq2.pop();
            }
        }

        // 결과 출력
        if (pq1.empty() || pq2.empty()) cout << "EMPTY\n";
        else cout << pq1.top() << " " << pq2.top() << "\n";
    }

    return 0;
}