#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct fireBall {
    pair<int, int> p = make_pair(0, 0); // 좌표
    int m = 0; // 질량
    int s = 0; // 속력
    int d = 0; // 방향

    fireBall() = default;

    fireBall (int ri, int ci, int mi, int si, int di) {
        p = make_pair(ri, ci);
        m = mi;
        s = si;
        d = di;
    }
};

typedef vector<vector<pair<int, vector<fireBall>>>> vvpivf;

pair<int, int> move(pair<int, int> p, int n, int d, int s) {
    int nx = p.first + dx[d] * s;
    int ny = p.second + dy[d] * s;

    nx = (nx + 10000 * n) % n;
    ny = (ny + 10000 * n) % n;

    return make_pair(nx, ny);
}

int dSame(vector<fireBall> &fbs) {
    // 첫 번째 원소가 짝수인지
    bool target = (fbs[0].d % 2 == 0);
    for (auto fb : fbs) {
        bool isEven = (fb.d % 2 == 0);
        if (isEven != target) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k; // 격자 칸, 파이어볼 개수, 명령 개수
    cin >> n >> m >> k;

    vector<fireBall> fbs;
    vector<fireBall> nfbs;

    for (int i = 0; i < m; ++i) {
        int ri, ci, mi, si, di;
        cin >> ri >> ci >> mi >> si >> di;

        // ri, ci는 1부터 시작하고 인덱스는 0부터 시작하므로
        fireBall fb = *new fireBall(ri-1, ci-1, mi, si, di);
        nfbs.push_back(fb);
    }

    while (k--) {
        // 파이어볼 리스트 갱신
        fbs = nfbs;

        // 새로운 명령을 위해 nfbs를 비운다
        nfbs.clear();

        // 같은 칸에 파이어볼이 있는지 확인하는 리스트
        vvpivf cnt = vvpivf(n, vector<pair<int, vector<fireBall>>>(n, make_pair(0, vector<fireBall>(0))));

        for (auto fb : fbs) {
            // 모든 파이어볼은 방향 d로 s칸 이동한다
            fb.p = move(fb.p, n, fb.d, fb.s);

            // 이동한 칸에 파이어볼이 있음을 표시해준다
            cnt[fb.p.first][fb.p.second].first++;
            cnt[fb.p.first][fb.p.second].second.push_back(fb);
        }

        // TODO: 테스트 출력
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                cout << cnt[i][j].first << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;

        // 같은 칸에 있는 파이어볼을 구한다
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // 파이어볼이 없는 칸은 스킵
                if (cnt[i][j].first == 0) continue;

                // 파이어볼이 1개라면 nfbs에 넣고 스킵
                if (cnt[i][j].first == 1) {
                    nfbs.push_back(cnt[i][j].second[0]);
                    continue;
                }

                // 파이어볼이 2개 이상인 칸에서 작업 수행
                // 파이어볼의 질량과 속력을 나누기 위해 합을 먼저 구한다
                int ms = 0; // 질량의 합
                int ss = 0; // 속력의 합
                for (auto elem : cnt[i][j].second) {
                    ms += elem.m;
                    ss += elem.s;
                }

                // 새로운 질량과 속력 계산
                int nm = ms / 5;
                int ns = ss / int(cnt[i][j].second.size());

                // 질량이 0인 파이어볼은 소멸 >>> 새로운 파이어볼을 계산하지 않고 다음 칸으로 넘어간다
                if (nm == 0) continue;

                // 합쳐지는 파이어볼의 방향이 모두 홀수이거나 짝수인지에 따라 방향을 결정
                bool isDSame = dSame(cnt[i][j].second);
                for (int l = 0; l < 4; ++l) {
                    int nd = isDSame ? l*2 : l*2+1;
                    fireBall nfb = *new fireBall(i, j, nm, ns, nd);
                    nfbs.push_back(nfb);
                }
            }
        }
    }

    // 명령이 끝난 후 남아있는 파이어볼 질량의 합 계산
    int ret = 0;
    for (auto fb : nfbs) {
        ret += fb.m;
    }

    cout << ret << "\n";

    return 0;
}

// https://hoony-devblog.tistory.com/45를 참고하여 move 함수 수정