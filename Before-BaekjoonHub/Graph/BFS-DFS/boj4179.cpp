#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define MAX 1003

int r, c;
string s;
char miro[MAX][MAX];
int jihoon[MAX][MAX];
int fire[MAX][MAX];
int ret = INF;

int x, y, nx, ny;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> jq; // 지훈 BFS
queue<pair<int , int>> fq; // 불 BFS

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    // 입력
    for (int i = 0; i < r; ++i) {
        cin >> s;
        for (int j = 0; j < c; ++j) {
            miro[i][j] = s[j];
            fire[i][j] = INF; // fire 초기화
            jihoon[i][j] = -1;
            if (s[j] == 'J') {
                jihoon[i][j] = 0;
                jq.push({i, j}); // 지훈이 시작점
            }
            if (s[j] == 'F') {
                fq.push({i, j}); // 불 시작점
                fire[i][j] = 0;
            }
        }
    }

    // 지훈이 계산
    while(!jq.empty()) {
        x = jq.front().first;
        y = jq.front().second;
        jq.pop();

        for (int i = 0; i < 4; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                if (miro[nx][ny] == '#') {
                    continue;
                }

                // not visited
                if (jihoon[nx][ny] == -1) {
                    jihoon[nx][ny] = jihoon[x][y] + 1;
                    jq.push({nx, ny});
                }
            }
        }
    }

    // 불 계산
    while(!fq.empty()) {
        x = fq.front().first;
        y = fq.front().second;
        fq.pop();

        for (int i = 0; i < 4; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                if (miro[nx][ny] == '#' || fire[nx][ny] != INF) continue;

                fire[nx][ny] = min(fire[nx][ny], fire[x][y] + 1);
                fq.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            // 미로의 가장자리에 도착
            if (i ==  0 || j == 0 || i == r-1 || j == c-1) {
                if (miro[i][j] == '#' || jihoon[i][j] == -1) continue;
                if (fire[i][j] > jihoon[i][j]) ret = min(ret, jihoon[i][j]);
            }
        }
    }

    if (ret >= INF) { // 미로를 탈출할 수 없는 경우
        cout << "IMPOSSIBLE" << "\n";
    } else {
        cout << ret + 1 << "\n";
    }

    return 0;
}

/*
 * 피드백 1 - fill()을 사용하여 초기화하자
 * 피드백 2 - ret을 while문 안에서 체크할 수 있다
 * */
