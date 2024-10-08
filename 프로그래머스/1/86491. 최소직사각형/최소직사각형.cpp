#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    vector<int> rows;
    vector<int> cols;
    
    // 가로에 큰 값을 몰고, 세로에 작은 값을 몰자
    for (auto size : sizes) {
        if (size[0] < size[1]) swap(size[0], size[1]);
        rows.push_back(size[0]);
        cols.push_back(size[1]);
    }
    
    int rowMax = *max_element(rows.begin(), rows.end());
    int colMax = *max_element(cols.begin(), cols.end());
    
    return rowMax * colMax;
}