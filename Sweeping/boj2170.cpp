#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int x, y;
priority_queue<pair<int, int>> pq;

int cx, cy;
ll ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        // 끝 점 기준 정렬
        // 오름차순을 위해 음수로 삽입
        pq.push({-x, y});
    }

    cx = -pq.top().first; // 시작
    cy = pq.top().second; // 끝
    pq.pop();
    while (!pq.empty()) {
        if (cy >= -pq.top().first) {
            cy = max(cy, pq.top().second);
        }
        else {
            ret += (cy - cx);
            cx = -pq.top().first;
            cy = pq.top().second;
        }
        pq.pop();
    }
    ret += (cy - cx);

    cout << ret << "\n";

    return 0;
}