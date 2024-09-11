#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 접시의 수, 초밥의 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    // 입력
    vector<int> belt;
    for (int i = 0; i < n; i++) {
        int sushi;
        cin >> sushi;
        belt.push_back(sushi);
    }

    // belt * 2로 원형 구현
    for (int i = 0; i < n; i++) {
        belt.push_back(belt[i]);
    }

    unordered_map<int, int> um;

    // 쿠폰으로 받은 초밥을 먹고 시작
    um[c]++;

    // 0번째 원소부터 k개로 um 초기화
    for (int i = 0; i < k; i++) {
        um[belt[i]]++;
    }

    // 손님이 먹을 수 있는 초밥 가짓수의 최댓값
    int mx = 0;
    for (auto elem : um) {
        if (elem.second > 0) mx++;
    }


    // 1번째 원소부터 슬라이딩 윈도우로 초밥 갯수 갱신
    for (int i = 1; i < n; i++) {
        um[belt[i-1]]--;
        um[belt[i+k-1]]++;

        // value가 0보다 큰 key의 갯수로 손님이 먹은 초밥 카운트
        int cnt = 0;
        for (auto elem : um) {
            if (elem.second > 0) cnt++;
        }

        // 손님이 먹을 수 있는 초밥 가짓수의 최댓값 갱신
        if (cnt > mx) mx = cnt;
    }

    cout << mx;

    return 0;
}

// 1트: 완전탐색 > 시간초과
// 2트: unordered_map + 슬라이딩 윈도우 기법 > 마지막쯤에 틀렸습니다
// 3트: 0번째 결과를 mx에 반영