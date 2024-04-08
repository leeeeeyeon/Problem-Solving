#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define INF 987654321

// 조합
vector<vector<int>> combination(int n, int k) {
    vector<bool> v(n-k, false);
    v.insert(v.end(), k, true);

    vector<vector<int>> ret;
    do {
        vector<int> temp;
        for (int i = 0; i < n; ++i) {
            if (v[i]) temp.push_back(i);
        }
        ret.push_back(temp);
    } while (next_permutation(v.begin(), v.end()));

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> powers = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> powers[i][j];
        }
    }

    int ret = INF;
    vector<vector<int>> group = combination(n, n/2);

    // N/2명으로 이루어진 스타트 팀을 조합으로 구한다
    for (auto start : group) {
        // N명 중 start에 속하지 않은 사람은 링크 팀으로 배정
        vector<int> link;
        for (int i = 0; i < n; ++i) {
            if (find(start.begin(), start.end(), i) == start.end()) link.push_back(i);
        }

        // 팀 내에서 2명씩 짝짓는 경우의 수를 구해 팀의 능력치 계산
        int sPower = 0; // 1 2 3
        int lPower = 0; // 4 5 6
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                sPower += powers[start[i]][start[j]];
                lPower += powers[link[i]][link[j]];
            }
        }

        // 팀 능력치 차이가 최소가 되도록 ret 갱신
        ret = min(ret, abs(sPower-lPower));
    }

    cout << ret << "\n";

    return 0;
}

// 35분 소요