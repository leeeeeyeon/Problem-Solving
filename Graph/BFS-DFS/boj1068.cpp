#include <bits/stdc++.h>

using namespace std;

int n; // 노드의 개수
int target;

map<int, vector<int>> mp;
int ret;
int root;

void go(int k) {
    if (mp[k].empty() || (mp[k].size() == 1 && mp[k][0] == target)) {
        ret++;
        return;
    }

    for (auto elem : mp[k]) {
        if (elem == target) continue;
        go(elem);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;

        if (temp == -1) {
            root = i;
            continue;
        }
        mp[temp].push_back(i);
    }

    cin >> target;
    if (target == root) {
        cout << 0 << "\n";
        return 0;
    }

    mp[target].clear();

    go(root);

    cout << ret << "\n";

    return 0;
}