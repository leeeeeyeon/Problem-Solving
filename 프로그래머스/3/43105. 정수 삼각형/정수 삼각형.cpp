#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {    
    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if (i == 0) continue;
            
            // 0번째 원소는 i-1번째 행의 0번째 열 원소를 더해
            if (j == 0) triangle[i][j] += triangle[i-1][j];
            
            // i번째 원소는 i-1번째 행의 i-1번째 열 원소를 더해
            else if (j == i) triangle[i][j] += triangle[i-1][j-1];
            
            // 그 외에는 i-1번 째 행의 직전 열, 같은 열 비교
            else triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
        }
    }
    
    int answer = *max_element(triangle[triangle.size()-1].begin(), triangle[triangle.size()-1].end());
    
    return answer;
}