#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> vvi;

bool rampCnt(vector<int> &row, vector<bool> &ramp, int l) {
    for (int i = 0; i < row.size()-1; ++i) {
        // 다음 좌표가 높이 차가 1보다 크면 길이 될 수 없음
        if (abs(row[i]-row[i+1]) > 1) return false;

        // 다음 좌표가 1만큼 작은 경우
        if (row[i+1] == row[i]-1) {
            // 지나갈 좌표 중 L만큼의 같은 높이로 이루어져 있지 않다면 길이 될 수 없음
            for (int j = 1; j <= l; ++j) {
                if (row[i+j] != row[i]-1) return false;
            }
            // 경사로가 설치되었음을 표시
            for (int j = 1; j <= l; ++j) {
                ramp[i+j] = true;
            }

            i += (l-1);

            // 다음 좌표가 1만큼 클 경우
        } else if (row[i+1] == row[i]+1) {
            // 지나온 길이 l+1보다 짧으면 경사로 설치 불가
            if (i - l < -1) return false;
            // 지나온 좌표를 확인하며 L만큼 같은 높이로 이루어져 있는지 확인
            for (int j = 0; j < l; ++j) {
                if (row[i-j] != row[i]) return false;

                // 지나온 길에 경사로가 설치되었는지 확인
                if (ramp[i-j]) return false;
            }

            for (int j = 0; j < l; ++j) {
                ramp[i-j] = true;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >> n >> l;

    // i와 j를 거꾸로 한 2차원 벡터를 하나 더 만든다
    vvi rBoard = vvi(n, vector<int>(n, 0));
    vvi cBoard = vvi(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> rBoard[i][j];
            cBoard[j][i] = rBoard[i][j];
        }
    }

    int ret = 0;
    // 행 기준으로 지나갈 수 있는 길 count
    for (int i = 0; i < n; ++i) {
        vector<bool> ramp = vector<bool>(n, false);
        ret += rampCnt(rBoard[i], ramp, l);
    }

    // 열 기준으로 지나갈 수 있는 길 count
    for (int i = 0; i < n; ++i) {
        vector<bool> ramp = vector<bool>(n, false);
        ret += rampCnt(cBoard[i], ramp, l);
    }

    cout << ret << "\n";

    return 0;
}

// 참고: https://hagisilecoding.tistory.com/108
// 모든 길을 독립적으로 보기 때문에 행에서 설치한 경사로가 열에 영향을 미칠지 고려하지 않아도 됨