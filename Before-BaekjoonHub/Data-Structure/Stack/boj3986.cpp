#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v;
stack<char> s;
int ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }

    for (string elem: v) {
        stack<char> s;
        s.push(elem[0]);

        for (int i = 1; i < elem.size(); ++i) {
            if (!s.empty()) {
                char top = s.top();
                if (top == elem[i]) {
                    s.pop();
                    continue;
                } else {
                    s.push(elem[i]);
                }
            } else {
                s.push(elem[i]);
            }
        }
        if (s.empty()) ret++;
    }

    cout << ret << "\n";

    return 0;
}

/*
 * 피드백 1) 어떻게 풀지 모를 때는 문자열을 90도 회전해보거나, 뒤에 더 써보거나, 거꾸로 봐보자
 * 피드백 2) 이번 문제는 스택을 활용하여 푼다
 * 피드백 3) !s.empty() 대신 s.size()를 사용할 수 있다
 * 피드백 4) vector에 문자열 안 담고 바로 for문 n번 돌려도 된다
 * */
