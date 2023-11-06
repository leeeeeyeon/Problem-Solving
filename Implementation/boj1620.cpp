#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, string> p;

string temp;
int num;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        p[to_string(i)] = temp;
        p[temp] = to_string(i);
    }

    for (int i = 0; i < m; ++i) {
        cin >> temp;
        cout << p[temp] << "\n";
    }
    return 0;
}

/*
 * 피드백 1) int to string을 할 때는 to_string() 함수를 사용한다
 * 피드백 2) map에 {번호, 이름}과 {이름, 번호}를 둘 다 담으면 출력 시 조건문 분기를 하지 않아도 된다
 * */