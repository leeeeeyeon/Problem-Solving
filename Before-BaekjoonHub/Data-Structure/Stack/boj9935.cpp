#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    string bombStr;
    cin >> bombStr;

    stack<char> s;
    char lastChar = bombStr[bombStr.size() - 1];
    for (long unsigned int i = 0; i < str.size(); i++) {
        string tempStr; // pop한 문자열
        tempStr += lastChar;

        // 폭발 문자열의 마지막 글자가 아니면 스택에 넣어
        if (str[i] != lastChar) s.push(str[i]);
            // 마지막 글자라면 길이만큼 pop
        else {
            for (long unsigned int j = 0; j < bombStr.size() - 1; j++) {
                if (!s.empty()) {
                    tempStr += s.top();
                    s.pop();
                }
            }

            // pop한 문자열을 뒤집어
            reverse(tempStr.begin(), tempStr.end());

            // bombStr과 같다면 다음 탐색으로
            // 일치하지 않는다면 다시 스택에
            if (tempStr != bombStr) {
                for (char c : tempStr) s.push(c);
            }
        }
    }

    if (s.empty()) cout << "FRULA";
    else {
        string result;
        while (!s.empty()) {
            result += s.top();
            s.pop();
        }

        reverse(result.begin(), result.end());

        cout << result;
    }

    return 0;
}

// 1트: 완전탐색, 시간 초과 (44%)
// 피드백) bombStr의 "마지막" 원소를 기준으로 스택 활용 !!
