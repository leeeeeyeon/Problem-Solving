#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ll;

#define LINE_MAX 1<<31

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n; // 이미 가지고 있는 랜선의 개수, 필요한 랜선의 개수
    cin >> k >> n;

    vector<ll> lines = vector<ll>(k);
    for (int i = 0; i < k; ++i) {
        cin >> lines[i];
    }

    ll start = 1;
    ll end = LINE_MAX;
    ll ret = 0;

    while (end >= start) {
        ll mid = (start + end) / 2;

        ll sum = 0;
        for (auto elem : lines) {
            sum += elem / mid;
        }

        if (sum >= n) {
            ret = max(ret, mid);
        }

        if (sum < n) end = mid-1;
        else start = mid+1;
    }

    cout << ret << "\n";
}

// 피드백 1: N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다.
// 피드백 2: '최대' 랜선의 길이를 구해야 하므로 ret을 갱신하고 while문을 끝내면 안됨