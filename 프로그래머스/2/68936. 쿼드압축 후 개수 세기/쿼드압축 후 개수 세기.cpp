#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;

int one = 0;
int zero = 0;

// 모두 0이면 0, 모두 1이면 1, 다르면 -1
int allSame(int sx, int sy, int ex, int ey, vvi &arr) {
    int target = arr[sx][sy];
    for (int i = sx; i <= ex; i++) {
        for (int j = sy; j <= ey; j++) {
            if (arr[i][j] != target) return -1;
        }
    }
    
    return target;
}

void zip(int sx, int sy, int ex, int ey, int n, vvi &arr) {
    // 재귀 탈출 조건 1) {sx, sy} == {ex, ey}, 1칸까지 압축
    if (sx == ex && sy == ey) {
        if (arr[sx][sy] == 0) zero++;
        else one++;
        
        return;
    }
    
    // 재귀 탈출 조건 2) {sx, sy}부터 {ex, ey}까지 모든 원소가 0 또는 1
    int zipResult = allSame(sx, sy, ex, ey, arr);
    if (zipResult == 0) {
        zero++;
        return;
    }
    if (zipResult == 1) {
        one++;
        return;
    }
    
    zip(sx, sy, sx+n/2-1, sy+n/2-1, n/2, arr);
    zip(sx, sy+n/2, sx+n/2-1, ey, n/2, arr);
    zip(sx+n/2, sy, ex, sy+n/2-1, n/2, arr);
    zip(sx+n/2, sy+n/2, ex, ey, n/2, arr);
}
vector<int> solution(vvi arr) {
    int n = arr.size();
    zip(0, 0, n-1, n-1, n, arr);
    
    return {zero, one};
}