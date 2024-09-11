#include <bits/stdc++.h>

using namespace std;

int n, x, temp;
vector<int> v;
int i, j;
int sum;
int ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int k = 0; k < n; ++k) {
        cin >> temp;
        v.push_back(temp);
    }
    cin >> x;

    i = 0;
    j = v.size() - 1;

    sort(v.begin(), v.end());

    while (i < j) {
        sum = v[i] + v[j];
        if (sum == x) {
            ret ++;
            i++;
            j--;
        }
        else if (sum > x) j--;
        else i++;
    }

    cout << ret << "\n";

    return 0;
}