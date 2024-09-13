#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    // 이미 구명보트를 탔는지 여부
    vector<bool> visited = vector<bool>(people.size(), false);
    
    int idx = 0;
    for (int i = people.size()-1; idx <= i; i--) {
        if (people[i] + people[idx] <= limit) {
            idx++;
        }
        answer++;
    }
    
    return answer;
}