#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef vector<pair<int, int>> vpii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vpii arr = vpii(n);
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        arr[i] = {x, y};
    }

    vector<int> result = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            // i번째 사람보다 덩치가 큰 사람의 수 count
            if (arr[i].first < arr[j].first && arr[i].second < arr[j].second) result[i]++;
        }
    }

    for (int elem : result) cout << elem + 1 << ' ';

    return 0;
}