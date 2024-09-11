#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int n; // 식재료의 개수
int mp, mf, ms, mv; // 단백질, 지방, 탄수화물, 비타민 최소 영양성분
int p, f, s, v, c; // 단백질, 지방, 탄수화물, 비타민, 가격
int rc = INF; // 최소 비용
map<int, vector<vector<int>>> rv;

vector<vector<int>> arr;

int main() {
    cin >> n;
    cin >> mp >> mf >> ms >> mv;

    for (int i = 0; i < n; ++i) {
        cin >> p >> f >> s >> v >> c;
        arr.push_back({p, f, s, v, c});
    }

    for (int i = 1; i < (1 << n); ++i) {
        int sum = 0; // 최소 비용
        int sp = 0, sf = 0, ss = 0, sv = 0;
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) { // j번째 비트가 켜져있다면
                v.push_back(j + 1);
                sum += arr[j][4]; // 비용
                sp += arr[j][0]; // 단백질
                sf += arr[j][1]; // 지방
                ss += arr[j][2]; // 탄수화물
                sv += arr[j][3]; // 비타민
            }
        }
        // 모든 최저 영양소 기준 통과
        if (sp >= mp && sf >= mf && ss >= ms && sv >= mv) {
            if (rc >= sum) {
                rc = sum;
                rv[rc].push_back(v);
            }
        }
    }

    if (rc == INF) cout << -1 << "\n";
    else {
        sort(rv[rc].begin(), rv[rc].end());
        cout << rc << "\n";
        for (auto a : rv[rc][0]) {
            cout << a << " ";
        }
    }

    return 0;
}