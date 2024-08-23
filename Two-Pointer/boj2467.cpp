#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 전체 용액의 수
    cin >> n;

    vector<int> liquids = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> liquids[i];
    }

    int start = 0;
    int end = liquids.size() - 1;

    pair<int, int> result = {liquids[start], liquids[end]};

    while (start < end) {
        int temp = liquids[start] + liquids[end];

        if (abs(temp) < abs(result.first + result.second)) {
            result = {liquids[start], liquids[end]};
        }

        if (temp == 0) break;
        else if (temp < 0) start++;
        else end--;
    }

    cout << result.first << ' ' << result.second;

    return 0;
}
