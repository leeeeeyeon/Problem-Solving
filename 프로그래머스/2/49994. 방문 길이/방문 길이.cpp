#include <string>
#include <unordered_map>

using namespace std;

pair<int, int> move(int cx, int cy, char dir) {
    if (dir == 'U') {
        return make_pair(cx-1, cy);
    } else if (dir == 'D') {
        return make_pair(cx+1, cy);
    } else if (dir == 'R') {
        return make_pair(cx, cy+1);
    } else { // dir == 'L'
        return make_pair(cx, cy-1);
    }
}

int solution(string dirs) {
    // 처음 걸어본 길의 길이
    int answer = 0;
    
    int cx = 0;
    int cy = 0;
    
    unordered_map<string, bool> visited;
    
    // U(위), D(아래), R(오른쪽), L(왼쪽)
    for (char dir: dirs) {
        pair<int, int> nextPoint = move(cx, cy, dir);
        int nx = nextPoint.first;
        int ny = nextPoint.second;
        
        // 범위 밖으로 나간 경우 명령 무시
        if (nx < -5 || ny < -5 || nx > 5 || ny > 5) continue;
        
        // 갔던 길인지 확인
        string road1 = to_string(cx) + to_string(cy) + to_string(nx) + to_string(ny);
        string road2 = to_string(nx) + to_string(ny) + to_string(cx) + to_string(cy);
        
        if (!visited[road1] && !visited[road2]) {
            visited[road1] = true;
            visited[road2] = true;
            answer++;
        }
        
        cx = nx;
        cy = ny;
    }
    
    
    return answer;
}