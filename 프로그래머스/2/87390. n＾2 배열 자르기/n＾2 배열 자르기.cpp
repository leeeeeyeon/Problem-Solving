#include <string>
#include <vector>

#define ROW first
#define COL second

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> arr;
    
    // arr[k]는 k/5행 k%5열의 원소
    pair<int, int> leftPoint = { left / n, left % n };
    pair<int, int> rightPoint = { right / n, right % n };
    
    for (int i = leftPoint.ROW; i <= rightPoint.ROW; i++) { // i번째 행에 대해
        // 만약 left를 포함하는 행이라면 left부터 끝까지만 사용
        if (i == leftPoint.ROW) {
            int end;
            // left, right이 같은 행에 존재
            if (i == rightPoint.ROW) end = rightPoint.COL;
            else end = n-1;
            
            for (int j = leftPoint.COL; j <= end; j++) {
                if (j <= i) arr.push_back(i+1);
                else arr.push_back(j+1);
            }
        }
        
        // 만약 right를 포함하는 행이라면 0부터 right까지만 사용
        else if (i == rightPoint.ROW) {
            for (int j = 0; j <= rightPoint.COL; j++) {
                if (j <= i) arr.push_back(i+1);
                else arr.push_back(j+1);
            }
        }
        
        // 그 사이 행이라면 전체 사용
        else {
            for (int j = 0; j < n; j++) {
                if (j <= i) arr.push_back(i+1);
                else arr.push_back(j+1);
            }
        }
    }
    
    return arr;
}

// 반례 참고) https://school.programmers.co.kr/questions/78425
// left와 right이 같은 행에 있을 때는 반복문 끝나는 지점이 right의 열까지만
