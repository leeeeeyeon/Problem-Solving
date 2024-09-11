#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // min(n, m) mod 2 = 0 >>> n과 m 둘 중 하나는 짝수
    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> arr = vector<vector<int>>(n, vector<int>(m, 0));
    vector<vector<int>> next = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            next[i][j] = arr[i][j];
        }
    }

    // 몇 겹이 생기냐? >>> min(n, m) / 2겹
    int repeat = min(n, m) / 2;

    // r번만큼 회전
    while (r--) {
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
        arr = next;
        for (int j = 0; j < repeat; ++j) {

            int cx = j;
            int cy = j;

            while (!visited[cx][cy]) {
                visited[cx][cy] = true;

                // 한 칸 아래로 이동
                if (cy == j && cx != n-1-j) {
                    next[cx+1][cy] = arr[cx][cy];
                    cx++;
                }

                    // 한 칸 오른쪽으로 이동
                else if (cx == n-1-j && cy != m-1-j) {
                    next[cx][cy+1] = arr[cx][cy];
                    cy++;
                }

                    // 한 칸 위로 이동
                else if (cy == m-1-j && cx != j) {
                    next[cx-1][cy] = arr[cx][cy];
                    cx--;
                }

                    // 한 칸 왼쪽으로 이동
                else if (cx == j && cy != j) {
                    next[cx][cy-1] = arr[cx][cy];
                    cy--;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << next[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// 참고: https://howudong.tistory.com/172
// 처음에 시간 초과가 났다 >>> arr = next를 한 겹마다 하는 것이 아니라 회전할 때마다 해야 한다