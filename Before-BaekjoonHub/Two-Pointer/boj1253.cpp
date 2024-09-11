#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<ll> arr;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        arr.push_back(elem);
    }

    sort(arr.begin(), arr.end());

    // 최소 원소 3개는 있어야 하나가 다른 수 2개의 합으로 나타낼 수 있음
    if (n <= 2) {
        cout << 0;
        return 0;
    }

    int cnt = 0; // 좋은 수의 개수

    // arr[i]의 범위가 매우 큰 점 주의
    // 현재 위치보다 왼쪽에 있는 원소들로 투 포인터 진행
    for (int i = 0; i < n; i++) {
        // 자기 자신 + 0 = 자기 자신이 되는 경우 방지
        int left = (i == 0) ? 1 : 0;
        int right = (i == n-1) ? n-2 : n-1;

        // 좋은 수를 찾을 수 없는 경우: left >= right일 때
        while (left < right) {
            ll sum = arr[left] + arr[right];

            // sum이 arr[i]보다 크면 right--
            // sum이 arr[i]보다 작으면 left++
            if (sum > arr[i]) {
                right--;
                if (right == i) right--;
            }
            else if (sum < arr[i]) {
                left++;
                if (left == i) left++;
            }
                // sum == arr[i] >>> 좋은 수
            else {
                cnt++;
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}

// 처음에 가장 작은 수(=arr[0])는 다른 두 수의 합이 될 수 없다고 생각했는데 음수 2개의 합일 경우 가능
// 반례 참고: https://www.acmicpc.net/board/view/100953