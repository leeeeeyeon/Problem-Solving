#include <bits/stdc++.h>

using namespace std;

int n; // 회의의 수
vector<pair<int, int>> arr; // 회의의 정보 {끝, 시작}
int s, e; // 시작, 끝
pair<int, int> temp; // {끝, 시작}
int ret; // 회의의 최대 개수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s >> e;
        arr.push_back({e, s});
    }

    // 끝나는 시간을 기준으로 정렬
    sort(arr.begin(), arr.end());
    temp = arr[0];
    ret++;

    for (int i = 1; i < arr.size(); ++i) {
        if (temp.first <= arr[i].second) {
            temp = arr[i];
            ret++;
        }
    }

    cout << ret << "\n";

    return 0;
}