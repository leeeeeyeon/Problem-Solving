#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> v;
map<int, int> ret;

bool allSame(int sx, int sy, int ex, int ey) {
    int target = v[sx][sy];
    for (int i = sx; i <= ex; ++i) {
        for (int j = sy; j <= ey; ++j) {
            if (v[i][j] != target) return false;
        }
    }

    return true;
}

void go(int sx, int sy, int ex, int ey) {
    if (allSame(sx, sy, ex, ey)) { // 종료 조건
        ret[v[sx][sy]] += 1;
        return;
    }

    int k = (ex - sx + 1) / 3;

    go(sx, sy, sx+k-1, sy+k-1);
    go(sx, sy+k, sx+k-1, sy+2*k-1);
    go(sx, sy+2*k, sx+k-1, sy+3*k-1);

    go(sx+k, sy, sx+2*k-1, sy+k-1);
    go(sx+k, sy+k, sx+2*k-1, sy+2*k-1);
    go(sx+k, sy+2*k, sx+2*k-1,sy+3*k-1);

    go(sx+2*k, sy, sx+3*k-1, sy+k-1);
    go(sx+2*k, sy+k, sx+3*k-1, sy+2*k-1);
    go(sx+2*k, sy+2*k, sx+3*k-1, sy+3*k-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> n;
    for (int i = 0; i < n; ++i) {
        vector<int> row;
        for (int j = 0; j < n; ++j) {
            int temp;
            cin >> temp;
            row.push_back(temp);
        }
        v.push_back(row);
    }

    go(0, 0, n-1, n-1);

    // 출력
    cout << ret[-1] << "\n";
    cout << ret[0] << "\n";
    cout << ret[1] << "\n";

    return 0;
}
