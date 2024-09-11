#include <bits/stdc++.h>

using namespace std;

int n;
int m;
vector<int> v;

int ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int i = 0;
    int j = v.size() - 1;
    int sum = 0;

    while (i < j) {
        sum = v[i]+v[j];
        if (sum == m) {
            ret++;
            i++;
            j--;
        }
        else if (sum < m) {
            i++;
        }
        else if (sum > m) {
            j--;
        }
    }

    cout << ret << "\n";

    return 0;
}