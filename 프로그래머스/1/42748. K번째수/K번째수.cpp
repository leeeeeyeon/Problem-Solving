#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int> command : commands) {
        // 배열의 인덱스가 0부터 시작하므로 -1
        int i = command[0]-1;
        int j = command[1]-1;
        int k = command[2];
        
        // array를 i번째부터 j번째까지 자른다
        vector<int> subArr = vector<int>(array.begin()+i, array.begin()+j+1);
        
        // subArr를 정렬한다
        sort(subArr.begin(), subArr.end());
        
        // subArr의 k번째 수를 answer에 삽입한다
        answer.push_back(subArr[k-1]);
    }
    
    return answer;
}