#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
int n; // 회원의 수
vector<vector<int>> arr = vector(51, vector<int>(51, INF));
int a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (true) {
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    // 플로이드 워셜 알고리즘 수행
    for (int k = 1; k < n+1; ++k) {
        for (int i = 1; i < n+1; ++i) {
            for (int j = 0; j < n+1; ++j) {
                if (i == j) arr[i][j] = 0;
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    // 각 회원의 점수 계산
    vector<int> candidate = vector<int>(n+1);
    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < n+1; ++j) {
            if (arr[i][j] > candidate[i]) candidate[i] = arr[i][j];
        }
    }

    int score = INF;
    vector<int> ret;

    // 회장 후보의 점수 계산
    for (int i = 1; i < n+1; ++i) {
        if (candidate[i] < score) score = candidate[i];
    }

    // 회장 후보 계산
    for (int i = 1; i < n+1; ++i) {
        if (candidate[i] == score) {
            ret.push_back(i);
        }
    }

    cout << score << " " << ret.size() << "\n";
    for (auto elem : ret) {
        cout << elem << " ";
    }

    return 0;
}

// 피드백) 플로이드 워셜 알고리즘에서 3중 반복문을 돌 때 k, i, j 순임을 주의하기