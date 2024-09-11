typedef long long ll;

bool isOne(ll x) {
    while (x >= 5) {
        // 해당 인덱스의 수는 0
        if (x % 5 == 2) return false;

        x /= 5;
    }

    return x != 2;
}

int solution(int n, ll l, ll r) {
    int answer = 0; // 값이 1인 인덱스 수

    for (ll i = l-1; i < r; i++) {
        if (isOne(i)) answer++;
    }

    return answer;
}