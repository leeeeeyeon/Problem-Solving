#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, w, x, y;
    cin >> h >> w >> x >> y;

    vvi a = vvi(h, vector<int>(w, 0));
    vvi b = vvi(h+x, vector<int>(w+y, 0));

    for (int i = 0; i < h+x; i++) {
        for (int j = 0; j < w+y; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int oi = i-x;
            int oy = j-y;

            if (oi < 0 || oy < 0) a[i][j] = b[i][j];
            else a[i][j] = b[i][j] - a[oi][oy];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}