#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr = vector<int>(n+1);
    // dp[i] = arr[i]를 마지막 원소로 하는 가장 긴 감소하는 부분 수열의 길이
    vector<int> dp = vector<int>(n+1, 1);

    for (int i = 1; i < n+1; ++i) {
        cin >> arr[i];

        for (int j = 1; j < i; ++j) {
            if (arr[i] < arr[j]) dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int ret = 0;
    for (auto elem : dp) {
        if (elem > ret) ret = elem;
    }

    cout << n-ret << "\n";
}

/*
 * 피드백 1) 이번 문제는 가장 긴 '감소하는' 부분 수열. N의 범위가 작아서 O(N^2) 알고리즘으로 풀었다
 * 피드백 2) 처음에는 dp를 0으로 초기화하고 if문 아래 else dp[i] = max(dp[i], 1)이라는 코드가 있었는데
 * dp 배열을 1로 초기화하여 해당 코드를 생략할 수 있었다.
 * */