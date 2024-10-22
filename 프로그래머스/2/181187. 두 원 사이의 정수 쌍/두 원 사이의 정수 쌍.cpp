#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    int mx = max(r1, r2);
    int mn = min(r1, r2);
    
    // x=0, y=0에서 구할 수 있는 점의 수 * 2 == (mx-mn+1)*4
    answer += (mx-mn+1)*4;
    
    // 1사분면에서 구할 수 있는 점의 수 * 4
    for (int i = 1; i < mx; i++) {
        double left = max(0.0, ceil(sqrt(pow(mn, 2) - pow(i, 2))));
        double right = floor(sqrt(pow(mx, 2) - pow(i, 2)));
        
        int diff;
        if (left == 0.0) diff = right - left;
        else diff = right - left + 1;
        
        answer += diff * 4;
    }
    
    return answer;
}