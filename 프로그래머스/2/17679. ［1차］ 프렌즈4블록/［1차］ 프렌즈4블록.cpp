#include <string>
#include <vector>

using namespace std;

typedef vector<vector<bool>> vvb;

int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};

// 2x2 블록을 지우고 지워진 블록 유무를 반환
bool popBlock(vector<string> &board, int &answer) {
    bool isPoped = false;
    vvb visited = vvb(board.size(), vector<bool>(board[0].size(), false));
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            // 블록이 없는 칸은 PASS
            if (board[i][j] == '0') continue;
            
            char target = board[i][j];
            bool isSameBlock = true;
            for (int k = 0; k < 3; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) {
                    isSameBlock = false;
                    break;
                }
                if (board[nx][ny] != target) {
                    isSameBlock = false;
                    break;
                }
            }
            
            if (isSameBlock) {
                isPoped = true;
                visited[i][j] = true;
                for (int k = 0; k < 3; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    visited[nx][ny] = true;
                }
            }
        }
    }
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (visited[i][j]) {
                board[i][j] = '0';
                answer++;
            }
        }
    }    
    
    return isPoped;
}

// 위에 있는 블록이 아래로 떨어져 빈 공간을 채움
void moveBlocks(vector<string> &board) {
    // 각 열에 대해 반복문 수행
    for (int j = 0; j < board[0].size(); j++) {
        // 열을 string으로 만들어 (colStr)
        string colStr = "";
        for (int i = 0; i < board.size(); i++) {
            colStr += board[i][j];
        }
        
        // colStr을 재조립해
        string newStr = "";
        string alphaStr = "";
        for (int i = 0; i < colStr.size(); i++) {
            if (colStr[i] == '0') newStr += colStr[i];
            else alphaStr += colStr[i];
        }
        newStr += alphaStr;
        
        for (int i = 0; i < board.size(); i++) {
            board[i][j] = newStr[i];
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    // 더 이상 사라질 블록이 없을 때까지
    while(true) {
        // 2x2 형태로 붙은 블록을 찾아 지운다
        bool isPoped = popBlock(board, answer);
        
        // 더 이상 지울 블록이 없다면 while문 종료
        if (!isPoped) break;
        
        // 블록을 아래로 내린다
        moveBlocks(board);
    }
    
    return answer;
}