#include <iostream>
#include <set>

using namespace std;

int map[5][5];
set<int> s;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void DFS(int x, int y, int num, int len) {
    if (len == 6) {
        s.insert(num);
        return;
    }

    for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >=0 && nx < 5 && ny >=0 && ny < 5) {
            DFS(nx, ny, num * 10 + map[nx][ny], len + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            DFS(i, j, map[i][j], 1);
        }
    }

    cout << s.size() << '\n';

    return 0;
}