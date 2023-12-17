#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; // 유저의 수, 친구 관계의 수
    cin >> n >> m;
    vector<vector<int>> arr = vector(n+1, vector<int>(n+1, INF));

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for (int k = 0; k < n+1; ++k) {
        for (int i = 0; i < n+1; ++i) {
            for (int j = 0; j < n+1; ++j) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    vector<int> ret = vector<int>(n+1);
    for (int i = 1; i < n+1; ++i) {
        int sum = 0;
        for (int j = 1; j < n+1; ++j) {
            sum += arr[i][j];
        }
        ret[i] = sum;
    }

    int min = INF;
    for (int i = 1; i < n + 1; ++i) {
        if (ret[i] < min) min = ret[i];
    }

    for (int i = 1; i < n+1; ++i) {
        if (min == ret[i]) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}