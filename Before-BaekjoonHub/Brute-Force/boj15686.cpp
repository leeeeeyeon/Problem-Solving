#include <bits/stdc++.h>

using namespace std;

#define INF 10e6

int n, m; // n - 도시의 크기가 n*n, m - 폐업 X인 치킨집의 개수
vector<pair<int, int>> homes; // 집들의 좌표
vector<pair<int, int>> chickens; // 치킨집들의 좌표
vector<int> temp; // 치킨집 M개를 고른 배열 (index를 저장)
vector<vector<int>> temps; // temp의 조합
int ret = INF; // 도시의 치킨 거리

void combi(int start, vector<int> temp) {
    if (temp.size() == m) {
        temps.push_back(temp);
        return;
    }

    for (int i = start+1; i < chickens.size(); ++i) {
        temp.push_back(i);
        combi(i, temp);
        temp.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    // 입력
    int k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> k;
            // 집과 치킨집의 좌표를 배열에 저장
            if (k == 1) homes.push_back({i, j});
            if (k == 2) chickens.push_back({i, j});
        }
    }

    // chickens에서 폐업되지 않은 치킨집 M개의 경우의 수를 구한다.
    combi(-1, temp);

    // 반복문을 통해 치킨 거리를 구한다.
    for (auto temp : temps) { // ex) [1,2]
        pair<int, int> c;
        int sum = 0;
        int dist;
        for (auto h : homes) {
            int home = INF;
            for (auto elem : temp) {
                c = chickens[elem];
                dist = abs(h.first - c.first) + abs(h.second - c.second);
                home = min(home, dist);
            }
            sum += home;
        }
        ret = min(ret, sum);
    }

    cout << ret << "\n";

    return 0;
}