#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> n) {
        ll num = 1;
        ret = 1;
        while (num % n != 0) {
            ret++;
            num *= 10;
            num ++;
            num %= n;
        }
        cout << ret << "\n";
    }
    return 0;
}

/*
 * 피드백) 숫자가 엄청 커지는 것을 방지하기 위해 modular 연산을 사용한다
 */