#include <iostream>
#include <stack>

#define MAX_N 500'000
#define HEIGHT first
#define INDEX second

using namespace std;

int towers[MAX_N];
int received[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 탑의 수
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> towers[i];
    }

    if (n == 1) {
        cout << 0;
    } else {
        stack<pair<int, int>> s; // {탑의 높이, 탑의 번호}
        s.push({towers[0], 1});

        for (int i = 1; i < n; i++) {
            // top이랑 높이 비교
            while (!s.empty()) {
                // 만약 top의 높이가 나보다 높다면 received[i] = top.INDEX
                if (s.top().HEIGHT > towers[i]) {
                    received[i] = s.top().INDEX;
                    break;
                }
                    // 만약 top의 높이가 나보다 낮다면 pop
                else s.pop();
            }

            s.push({towers[i], i+1});
        }

        for (int i = 0; i < n; i++) cout << received[i] << ' ';
    }

    return 0;
}

// 1트: DP - 만약 towers[dp[i-1]-1]이 현재 탑보다 높이가 낮아도 dp[i]로 저장됨