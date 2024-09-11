#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, c;

ll mod(ll a, ll b) {
    if (b == 1) return a % c;

    ll ret = mod(a, b / 2);
    ret = (ret * ret) % c;

    if (b % 2) ret = (ret * a) % c; // 홀수일 경우 a를 1번 더 곱해야 함

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    cout << mod(a, b) << "\n";

    return 0;
}

/*
 * 피드백 1) a^(2k) = a^k * 2^k 로 나누어 생각할 수 있다
 * 피드백 2) b가 홀수일 경우 a를 1번 더 곱해야 한다
 * 피드백 3) b%2로 b의 짝수/홀수 여부를 판단할 수 있다 (b%2==0을 줄여서 쓸 수 있음)
 * */