#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef vector<vector<bool>> vvb;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> land) {
    int answer = 0;
    vector<int> total = vector<int>(land[0].size(), 0);

    // 1. 0번째 열부터 시작하여 한 칸씩 내려가면서 그 칸을 시작점으로 BFS를 진행
    for(int j=0; j<land[0].size(); j++) { // 열
        for(int i=0; i<land.size(); i++) { // 행
            // 이미 방문한 땅이거나 빈 땅일 경우
            if (land[i][j] == 0) continue;

            // BFS
            queue<pair<int, int>> q;
            set<int> s; // BFS 탐색 시 추출하는 열의 좌표

            q.push({i, j}); // {행, 열, cnt}
            s.insert(j);
            land[i][j] = 0; // 방문한 칸은 0으로 만든다

            int cnt = 1;

            while(!q.empty()) {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();

                for(int k=0; k<4; k++) {
                    int nx = cx + dx[k];
                    int ny = cy + dy[k];

                    // Index out of range
                    if (nx < 0 || ny < 0 || nx >= land.size() || ny >= land[0].size()) continue;
                    // 빈 땅인 경우
                    if (land[nx][ny] == 0) continue;

                    s.insert(ny);
                    land[nx][ny] = 0;
                    cnt++;

                    q.push({nx, ny});
                }
            }

            for (auto elem : s) {
                total[elem] += cnt;
            }
        }
    }

    for (auto elem : total) {
        if (elem > answer) answer = elem;
    }

    return answer;
}