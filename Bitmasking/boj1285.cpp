#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
int n; // 한 행(열)에 놓인 동전의 수
int a[24]; // 각 행을 정수로 표현
int ret = INF; // 동전의 최소 개수

void go(int here) {
    if (here == n+1) { // 마지막 행까지 탐색을 완료했을 때
        int sum = 0; // T의 개수
        for (int i = 1; i <= (1 << (n-1)) ; i*= 2) { // 각 열을 2의 제곱으로 생각 (1, 2, 4 ...)
            int cnt = 0; // 각 행의 T의 개수
            for (int j = 1; j <= n; ++j) { // 각 행을 체크
                if (a[j] & i) cnt ++; // 임의의 열에서 T의 개수를 저장
            }
            // T와 N의 개수 중 작은 쪽을 sum에 더한다
            // N의 개수를 더한다 = 열을 뒤집는다
            sum += min(cnt, n - cnt);
        }
        ret = min(ret, sum);
        return;
    }

    go(here+1); // 뒤집지 않고 다음 행으로 이동
    a[here] = ~a[here]; // 행을 뒤집는다
    go(here+1); // 다음 행으로 이동
}

int main() {

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        string s;
        int temp = 1;

        cin >> s;
        for (int j = 0; j < n; ++j) {
            // H = 0, T = 1로 하여 한 행을 자연수로 표현한다.
            if (s[j] == 'T') a[i] |= temp;
            temp *= 2;
        }
    }

    go(1);
    cout << ret << "\n";

    return 0;
}

/*
 * 핵심 1 - 비트마스킹 사용하기
 * 핵심 2 - 행을 뒤집으면, 열 뒤집기 여부는 결정된다
 * */