#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> arr = vector(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];

            if (arr[i][j] == 0) arr[i][j] = INF;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] >= INF) cout << 0 << " ";
            else cout << 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}