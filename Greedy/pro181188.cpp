#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b) {
    if (a[1] < b[1]) return true;

    return false;
}


int solution(vector<vector<int>> targets) {
    int answer = 0;

    sort(targets.begin(), targets.end(), comp);

    int e = 0;

    for (auto target : targets) {
        if (target[0] >= e) {
            answer ++;
            e = target[1];
        }
    }

    return answer;
}