#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int m;
int elem;

int l, r;

int binary_search(int target, vector<int> &v) {
    l = 0;
    r = v.size() - 1;

    int mid;
    while (l <= r) {
        mid = (l + r) / 2;

        if (target < v[mid]) r = mid - 1;
        else if (target == v[mid]) return 1;
        else l = mid + 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--) {
        vector<int> v1;

        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> elem;
            v1.push_back(elem);
        }
        sort(v1.begin(), v1.end());

        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> elem;
            cout << binary_search(elem, v1) << "\n";
        }
    }

    return 0;
}

/*
 * 피드백 1) 재귀 대신 while문 사용 가능
 * 피드백 2) 테스트 케이스 돌릴 때 for문 대신 while(t--) 쓰니까 깔끔
 * 피드백 3) 테스트 케이스마다 v1 초기화해주기! 그렇게 안하면 v1에 계쇡 원소 쌓임
 * */