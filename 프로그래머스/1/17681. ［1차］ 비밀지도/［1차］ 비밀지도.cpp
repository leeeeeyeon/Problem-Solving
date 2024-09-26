#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < n; i++) {
        // arr1[i]랑 arr2[i]를 OR 연산한다
        int num = arr1[i] | arr2[i];
        
        // 반복문을 돌면서 i번째 자리가 1이면 '#', 0이면 공백
        string elem = "";
        for (int i = 1; i <= n; i++) {
            int cmp = (1 << (n-i));
            int result = (num & cmp);
            
            if (result != 0) elem += "#";
            else elem += " ";
        }
        
        answer.push_back(elem);
    }
    
    return answer;
}