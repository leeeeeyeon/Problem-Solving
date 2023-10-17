#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    string s;
    cin >> s;

    // 0 - a, 1 - b ...로 알파벳을 담는 배열
    // 원소는 단어에 포함된 알파벳의 개수
    int arr[26] = {0};

    // 아스키 코드로 접근
    for (int i = 0; i < s.length(); ++i) {
        arr[s[i]-97] ++;
    }

    for (auto elem : arr) {
        cout << elem << " ";
    }
    return 0;
}