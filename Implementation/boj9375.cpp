#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        map<string, int> m;
        string a, b;
        for (int j = 0; j < n; ++j) {
            cin >> a >> b;

            // 맵에 현재 의상 종류가 있을 경우
            if (m.find(b) != m.end()) m[b] += 1;
            else m.insert({b, 1});
        }

        int ret = 1;
        for (auto elem : m) {
            ret *= elem.second + 1;
        }

        // 알몸인 상태 제외
        cout << ret - 1 << "\n";
    }

    return 0;
}