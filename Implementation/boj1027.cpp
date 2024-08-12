#include <iostream>
#include <algorithm>

#define MAX_N 50

using namespace std;

int buildings[MAX_N+1];
int cnt[MAX_N+1]; // 해당 빌딩에서 볼 수 있는 빌딩의 수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> buildings[i];
    }

    // 두 빌딩 A, B를 연결한 선분이 다른 빌딩을 지나면 안됨
    // 완전 탐색
    for (int i = 1; i <= n; i++) {
        // 빌딩이 1개일 때는 mx = 0
        if (n == 1) {
            cout << 0;
            return 0;
        }

        for (int j = i+1; j <= n; j++) {
            // 자기 자신을 서로 다른 빌딩으로 인식하는 경우 제외
            if (i == j) continue;

            // buildings[i]와 buildings[j]를 잇는 방정식 f(x)을 구해
            double dx = j - i;
            double dy = buildings[j] - buildings[i];
            double a = dy / dx; // 기울기

            // i와 j 사이에 있는 점에 대해 순회하면서
            bool cross = false;
            for (int k = i+1; k < j; k++) {
                // f(x)에 k 대입했을 때 값과 buildings[k] 비교
                double y = a * k - a * i + buildings[i]; // f(x)에 k 대입했을 때 값

                // 만약 buildings[k]가 더 크다면 break
                if (buildings[k] >= y) {
                    cross = true;
                    break;
                }
            }

            // 만약 break에 안 걸렸다면 cnt++
            // 주의: 높이가 낮은 빌딩에서 높은 빌딩을 보는 것도 포함해야 함 !!!
            if (!cross) {
                cnt[i]++;
                cnt[j]++;
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, cnt[i]);
    }

    cout << mx;

    return 0;
}