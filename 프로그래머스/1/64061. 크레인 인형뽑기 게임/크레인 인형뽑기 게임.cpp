#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    
    vector<stack<int>> stacks = vector<stack<int>>(n);
    for (int j = 0; j < n; j++) {
        for (int i = n-1; i >= 0; i--) {
            if (board[i][j] == 0) continue;
            stacks[j].push(board[i][j]);
        }
    }
    
    stack<int> bucket; // 바구니
    for (int move : moves) {
        move--; // 인덱스는 0부터 시작
        
        // 해당 열에 인형이 없으면 아무 일도 일어나지 x
        if (stacks[move].empty()) continue;
        
        int doll = stacks[move].top();
        stacks[move].pop();
        
        if (bucket.empty()) bucket.push(doll);
        else if (doll == bucket.top()) {
            bucket.pop();
            answer += 2;
        } 
        else {
            bucket.push(doll);
        }
    }
    
    return answer;
}