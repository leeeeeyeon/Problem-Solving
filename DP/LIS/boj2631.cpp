#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 아이들의 수
    cin >> n;

    vector<int> arr = vector<int>(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> dp;
    dp.push_back(0);

    for (int i = 1; i <= n; i++) {
        // 비어있거나 dp의 마지막 원소보다 현재 원소가 클 경우 현재 원소 추가
        if (dp.empty() || dp[dp.size()-1] < arr[i]) dp.push_back(arr[i]);

        // 그렇지 않다면 lower_bound를 현재 원소로 갱신
        int lb = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        dp[lb] = arr[i];
    }

    cout << n-dp.size()+1;

    return 0;
}

// LIS >>> 가장 긴 부분수열을 구해서 그 길이를 n에서 빼준다