#include <bits/stdc++.h>

using namespace std;

string s;
int i, j;
bool flag = true;

int main() {

    cin >> s;
    i = 0, j = s.length() - 1;

    while (i <= j) {
        if (s[i] != s[j]) {
            flag = false;
            break;
        }
        i ++;
        j --;
    }

    if (flag) cout << 1 << "\n";
    else cout << 0 << "\n";

    return 0;
}

/*
 * 피드백 - reverse()를 사용하여 문자열을 뒤집고 원본 문자열과 같은지 비교하는 방법도 있다
 * */