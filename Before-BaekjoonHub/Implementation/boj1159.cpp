#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    map<char, int> members;
    for (int i = 0; i < n; ++i) {
        string member;
        cin >> member;
        if (members.find(member[0]) != members.end()) members[member[0]]++;
        else members.insert({member[0], 1});
    }

    vector<char> c;
    for (auto elem : members) {
        if (elem.second >= 5) c.push_back(elem.first);
    }

    if (c.empty()) {
        cout << "PREDAJA" << "\n";
        return 0;
    }

    sort(c.begin(), c.end());

    for (auto elem : c) {
        cout << elem;
    }
    cout << "\n";

    return 0;
}