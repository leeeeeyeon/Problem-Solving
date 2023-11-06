#include <bits/stdc++.h>

using namespace std;

int n, k;
int temp;
vector<int> v;
int sum;
int ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < k; ++i) {
        ret += v[i];
    }
    sum = ret;

    for (int i = 1; i <= n-k ; ++i) {
        sum -= v[i-1];
        sum += v[i+k-1];
        ret = max(ret, sum);
    }

    cout << ret << "\n";

    return 0;
}