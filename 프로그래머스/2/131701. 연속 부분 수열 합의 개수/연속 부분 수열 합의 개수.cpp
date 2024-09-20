#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {    
    int length = elements.size();
    
    // 수열을 뒤에 1번 더 붙여서 원형 수열 구현
    for (int i = 0; i < length; i++) {
        elements.push_back(elements[i]);
    }
    
    unordered_set<int> us;

    for (int i = 0; i < length; i++) { // 시작 인덱스
        for (int j = 1; j <= length; j++) { // 연속 부분 수열의 길이
            int sum = 0;
            for (int k = 0; k < j; k++) {
                sum += elements[i+k];
            }
            
            us.insert(sum);
        }
    }
    
    return us.size();
}