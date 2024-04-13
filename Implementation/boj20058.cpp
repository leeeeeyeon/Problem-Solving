#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q; // 격자 칸, 단계 수
    cin >> n >> q;

    int N = pow(2, n);
    int sum = 0; // 남아있는 얼음의 합
    vector<vector<int>> board = vector<vector<int>>(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    vector<int> levels = vector<int>(q, 0);
    for (int i = 0; i < q; ++i) {
        cin >> levels[i];
    }

    for (int i = 0; i < q; ++i) {
        int l = levels[i];

        // 격자를 2^l * 2^l의 부분 격자로 나눈다
        // 모든 부분 격자를 90도 회전
        int L = pow(2, l);
        vector<vector<int>> temp = vector<vector<int>>(N, vector<int>(N, 0));
        for (int y = 0; y < N; y += L) {
            for (int x = 0; x < N; x += L) {
                for (int a = 0; a < L; ++a) {
                    for (int b = 0; b < L; ++b) {
                        temp[y + b][x + L - a - 1] = board[y + a][x + b];
                    }
                }
            }
        }

        board = temp;
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                cout << board[x][y] << " ";
            }
            cout << endl;
        }
        cout << endl;

        // 모든 칸을 순회하며 얼음이 있는 칸이 3개 이상 인접해 있지 않다면 얼음의 양을 1 줄인다
        vector<pair<int, int>> meltings;
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                // 인접한 칸 중 얼음이 있는 칸을 센다
                int cnt = 0;
                for (int m = 0; m < 4; ++m) {
                    int nx = j + dx[m];
                    int ny = k + dy[m];

                    // index out of range
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

                    if (board[nx][ny] > 0) cnt ++;
                }

                // 그 칸이 3보다 작다면 얼음의 양이 1 줄어든다
                // 얼음의 양은 0보다 작을 수 없다
                if (cnt < 3 && board[j][k] > 0) meltings.push_back({j, k});
            }
        }
        for (auto melting : meltings) {
            board[melting.first][melting.second]--;
        }
    }

    // 모든 칸을 순회하며 BFS로 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수를 센다
    int mx = 0;
    vector<vector<bool>> visited = vector<vector<bool>>(N, vector<bool>(N, false));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            sum += board[i][j];
            if (board[i][j] == 0) continue;

            queue<pair<int, int>> qq;
            int group = 0;

            if (!visited[i][j]) {
                qq.push({i, j});
                visited[i][j] = true;

                while (!qq.empty()) {
                    int cx = qq.front().first;
                    int cy = qq.front().second;

                    group++;
                    qq.pop();

                    for (int k = 0; k < 4; ++k) {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];

                        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                        if (board[nx][ny] == 0) continue;
                        if (visited[nx][ny]) continue;

                        qq.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }

                if (group > mx) mx = group;
            }
        }
    }


    cout << sum << "\n";
    cout << mx << "\n";

    return 0;
}

// 회전 & 얼음의 양 줄이기 & 가장 큰 덩어리 계산 3가지 파트로 이루어진 문제
// 회전 로직 참고: https://kimjingo.tistory.com/131
// 얼음의 양이 0 미만으로 줄어들 수 없다는 점 주의
// 얼음의 양을 줄일 때 이전 칸에서 줄어든 것이 현재 칸에 반영되면 안됨
// >>> 얼음이 줄어드는 칸을 리스트로 저장하고 리스트를 순회하며 얼음의 양을 줄여야 한다