#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        // 초기화: 1만 써서 그 수를 만드는 경우는 1가지
        vector<int> dp = vector<int>(n+1, 1);

        // 2와 3을 조합하는 경우 고려
        for (int i = 2; i <= n; i++) {
            dp[i] += dp[i-2];
        }

        for (int i = 3; i <= n; i++) {
            dp[i] += dp[i-3];
        }

        cout << dp[n] << '\n';
    }

    return 0;
}