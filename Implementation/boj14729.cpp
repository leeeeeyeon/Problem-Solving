#include <bits/stdc++.h>

using namespace std;

int n;
double score;
priority_queue<double> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> score;
        pq.push(-score);
    }

    for (int i = 0; i < 7; ++i) {
        cout << fixed;
        cout.precision(3);
        cout << -pq.top() << "\n";
        pq.pop();
    }

    return 0;
}

// N의 최댓값이 10,000,000이기 때문에 단순하게 정렬하면 안된다
// printf("%.3lf\n", i)로도 소수점 3자리까지 출력 가능