#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;

void dfs(int i, int end, int result, string str) {
    if (i == end) {
        if (result == 0) answer.push_back(str);
        return;
    }

    // 숫자 사이에 + 삽입
    string nextStr = str + "+" + to_string(i+1);
    dfs(i+1, end, result + (i+1), nextStr);

    // 숫자 사이에 - 삽입
    nextStr = str + "-" + to_string(i+1);
    dfs(i+1, end, result - (i+1), nextStr);

    // 숫자 사이에 공백 삽입해서 이어 붙임
    nextStr = str + " " + to_string(i+1);
    // 이전 부호가 +인지 -인지에 따라 result를 다르게 해야 함
    if (str.size() == 1) {
        dfs(i+1, end, 10*i + i+1, nextStr);
    } else {
        char prevOperator = str[str.size()-2];
        if (prevOperator == ' ') return;
        if (prevOperator == '+') {
            dfs(i+1, end, result - i + (10*i + i+1), nextStr);
        } else if (prevOperator == '-') {
            dfs(i+1, end, result + i - (10*i + i+1), nextStr);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        // answer 벡터 초기화
        answer = vector<string>(0);

        // N은 최대 9므로 숫자 사이 빈 칸은 최대 8개
        // 3^8=6561로 넉넉하니까 완전탐색 해보자
        dfs(1, n, 1, "1");

        sort(answer.begin(), answer.end());
        for (string elem : answer) {
            cout << elem << '\n';
        }
        cout << '\n';
    }

    return 0;
}