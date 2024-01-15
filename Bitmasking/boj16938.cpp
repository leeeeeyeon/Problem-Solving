#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
int n, l, r, x;
int ret;
int problems[15];

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; ++i) {
        cin >> problems[i];
    }

    for (int i = 1; i < (1<<n); ++i) {
        vector<int> v;
        int sum = 0;
        int mx = 0;
        int mn = INF;

        for (int j = 0; j < 15; ++j) {
            // j번째 자리가 1인 경우
            if (i & (1<<j)) {
                v.push_back(j);
                // 문제 난이도의 합 계산
                sum += problems[j];
                // 가장 어려운, 쉬운 문제 계산
                if (problems[j] > mx) mx = problems[j];
                if (problems[j] < mn) mn = problems[j];
            }
        }
        // 조건을 만족하지 않는다면 continue
        if (v.size() <= 1) continue;
        if (sum < l || sum > r) continue;
        if (mx - mn < x) continue;

        ret ++;
    }

    cout << ret << "\n";

    return 0;
}