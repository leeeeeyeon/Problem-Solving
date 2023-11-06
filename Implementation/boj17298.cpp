#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
stack<int> s;
vector<int> ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    ret = vector(n, -1);

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        while (s.size() && v[s.top()] < v[i]) {
            ret[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << ret[i] << " ";
    }
    return 0;
}

/*
 * 피드백) 스택을 활용하자
 */