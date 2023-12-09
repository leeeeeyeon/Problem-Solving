#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr = vector<int>(n+1);
    vector<int> dp;
    arr[0] = 0;

    for (int i = 1; i < n+1; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i < n+1; ++i) {
        // 비어있거나 dp의 마지막 원소보다 here이 크다면 dp에 here을 추가
        if (dp.empty() || dp.back() < arr[i]) {
            dp.push_back(arr[i]);
        } else { // 그렇지 않다면 lower_bound를 찾아 dp 배열 갱신
            int lb = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[lb] = arr[i];
        }
    }

    cout << dp.size() << "\n";
    return 0;
}

// 피드백 1: 가장 긴 '증가'하는 부분 수열이기 때문에 값이 동일한 것은 포함하지 않는다
// 피드백 2: lower_bound의 인자는 arr이 아니라 dp임을 주의하자