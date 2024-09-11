#include <bits/stdc++.h>

using namespace std;

int n, k; // 보석과 가방의 개수
vector<pair<int, int>> v; // {보석 가격, 무게}
vector<int> c; // 가방에 담을 수 있는 최대 무게
priority_queue<int> pq;
int x, y, z; // 보석 무게, 보석 가격, 가방에 담을 수 있는 최대 무게
long long ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    // 보석 정보
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    // 가방에 담을 수 있는 최대 무게
    for (int i = 0; i < k; ++i) {
        cin >> z;
        c.push_back(z);
    }
    sort(v.begin(), v.end());
    sort(c.begin(), c.end());

    int j = 0;
    for (int i = 0; i < k; ++i) {
        while (j < n && v[j].first <= c[i]) pq.push(v[j++].second);
        if (pq.size()) {
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret << "\n";

    return 0;
}