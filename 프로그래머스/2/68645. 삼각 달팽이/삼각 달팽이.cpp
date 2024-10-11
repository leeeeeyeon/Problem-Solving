#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;

int dx[3] = {1, 0, -1};
int dy[3] = {0, 1, -1};

vector<int> solution(int n) {
    vector<int> answer;
    
    vvi board = vvi(n, vector<int>(n, 0));
    
    // 이동 방향: 아래 > 오른쪽 > 왼쪽 대각선 위 반복
    int dir = 0;
    bool canMove = true;
    
    int number = 1;
    int cx = 0;
    int cy = 0;
    
    // number == (1부터 n까지의 합)일 때까지만 삼각형을 채움
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    
    while (number <= sum) {
        board[cx][cy] = number;
        
        int nx = cx + dx[dir%3];
        int ny = cy + dy[dir%3];
        
        // 방향을 바꾸어야 할 때 1) 한 칸 더 가면 index out of range
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
            dir++;
            nx = cx + dx[dir%3];
            ny = cy + dy[dir%3];
        }
        
        // 방향을 바꾸어야 할 때 2) 다음 칸 != 0
        else if (board[nx][ny] != 0) {
            dir++;
            nx = cx + dx[dir%3];
            ny = cy + dy[dir%3];
        }
        
        cx = nx;
        cy = ny;
        number++;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(board[i][j]);
        }
    }
    
    return answer;
}