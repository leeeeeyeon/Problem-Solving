#include <bits/stdc++.h>

using namespace std;

int n, h; // 동굴의 길이, 높이
int k; // 장애물의 크기

vector<int> v1, v2; // 종유석, 석순

pair<int, int> p;
int ret1, ret2, ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> h;
    p = {n, 1}; // 장애물의 최솟값, 구간의 수

    for (int i = 0; i < n; ++i) {
        cin >> k;
        // 석순과 종유석이 번갈아 나오므로 짝수, 홀수 여부로 나누어 배열에 저장
        if (i%2 == 0) v1.push_back(k); // 석순
        else v2.push_back(h-k); // 종유석
    }
    // 이분 탐색을 위한 정렬
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < h; ++i) {
        ret1 = v1.size() - (upper_bound(v1.begin(), v1.end(), 0.5+i) - v1.begin()); // 석순
        ret2 = upper_bound(v2.begin(), v2.end(), 0.5+i) - v2.begin(); // 종유석
        // 총 장애물 개수
        ret = ret1 + ret2;

        // 장애물이 더 적은 구간을 발견할 경우 갱신
        if (ret < p.first) p = {ret, 1};
            // 구간의 개수 count
        else if (ret == p.first) p.second ++;
    }

    cout << p.first << " " << p.second << "\n";

    return 0;
}

/*
 * 피드백 1) 석순과 종유석을 따로 관리한다
 * 피드백 2) 종유석은 h-k로 사용
 * 피드백 3) 직접 구현하지 않아도 된다면 내장 함수를 사용하자
 * */