#include <string>
#include <vector>
#include <algorithm>

#define MAX_N 500

using namespace std;

double ratio[MAX_N]; // i번 스테이지의 실패율

// 실패율 내림차순, 같으면 작은 번호가 먼저 오도록 정렬
bool comp(int a, int b) {
    if (ratio[a] == ratio[b]) {
        return a < b;
    }
    
    return ratio[a] > ratio[b];
}

vector<int> solution(int n, vector<int> stages) {
    vector<int> answer;
    
    // 1부터 n까지 수(스테이지 갯수)로 answer 배열 채워
    for (int i = 1; i <= n; i++) {
        answer.push_back(i);
    }
    
    // count[i] = (i번째 스테이지 도전 중인 사용자 수)
    vector<double> count = vector<double>(n+2, 0);
    
    for (auto elem : stages) {
        count[elem]++;
    }
    
    double sum = stages.size();
    for (int i = 1; i <= n; i++) {
        // sum이 0 이하가 되지 않도록 주의 !!
        if (count[i] > 0) {
            ratio[i] = count[i] / sum;
            sum -= count[i];
        }
    }
    
    sort(answer.begin(), answer.end(), comp);
    
    return answer;
}