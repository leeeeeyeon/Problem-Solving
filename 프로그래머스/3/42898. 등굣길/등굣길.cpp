#include <string>
#include <vector>
#include <algorithm>

#define divisor 1'000'000'007

using namespace std;

typedef vector<vector<int>> vvi;

// DP에 최단거리가 아닌 최단 경로로 가는 가짓수를 저장
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vvi dp = vvi(n, vector<int>(m, 0));
    
    // puddles에 있는 좌표는 dp에 -1로 저장
    for (auto puddle : puddles) {
        int x = puddle[1]-1;
        int y = puddle[0]-1;
        
        if (x == 0) {
            for (int j = y; j < m; j++) {
                dp[0][j] = -1;
            }
        } else if (y == 0) {
            for (int i = x; i < n; i++) {
                dp[i][0] = -1;
            }
        } else {
            dp[x][y] = -1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 0행이나 0열에 웅덩이가 있을 수 있으므로 먼저 처리
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            
            // 0행, 0열은 모두 1
            if (i == 0) dp[i][j] = 1;
            else if (j == 0) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % divisor;
        }
    }
    
    return dp[n-1][m-1];
}

// 참고: https://school.programmers.co.kr/questions/24593
