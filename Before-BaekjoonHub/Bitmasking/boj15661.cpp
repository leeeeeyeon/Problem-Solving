#include <bits/stdc++.h>

using namespace std;

#define INF 98765421

int n; // 전체 사람 수
int power[23][23]; // 능력치
int sp, lp;
int ret = INF;

int calcPower(vector<int> &v) {
    int p = 0;

    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v.size(); ++j) {
            p += power[v[i]][v[j]];
        }
    }

    return p;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> power[i][j];
        }
    }

    vector<int> ps(1 << n);

    for (int i = 1; i < (1<<n); ++i) { // 0001 ... 1111
        // 초기화
        vector<int> start;
        vector<int> link;
        sp = 0;
        lp = 0;

        // 비트마스킹으로 경우의 수 계산
        for (int j = 0; j < n; ++j) {
            if (i & (1<<j)) start.push_back(j);
            else link.push_back(j);
        }

        sp = calcPower(start);
        lp = calcPower(link);
        if (abs(sp - lp) < ret) ret = abs(sp - lp);
    }

    cout << ret << "\n";

    return 0;
}