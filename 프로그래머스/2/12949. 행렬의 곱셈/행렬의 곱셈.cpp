#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<vector<int>> vvi;

vvi solution(vvi arr1, vvi arr2) {
    vvi answer = vvi(arr1.size());
    
    for (int i = 0; i < arr1.size(); i++) { // arr1의 행
        for (int j = 0; j < arr2[0].size(); j++) { // arr2의 열
            int sum = 0;
            for (int k = 0; k < arr1[0].size(); k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            answer[i].push_back(sum);
        }
    }
    
    return answer;
}