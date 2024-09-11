#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

typedef tuple<int, int, int> tiii;

struct cmp {
    bool operator()(tiii a, tiii b) {
        return get<2>(a) < get<2>(b);
    }
};

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0; // 피로도

    int pickSum = 0;
    // 곡괭이로 채굴 가능한 구간 수 계산
    for (int pick : picks) {
        pickSum += pick;
    }

    // 우선순위 큐(pq) 커스텀: (a, b, c)일 때 a가 큰 순 > b가 큰 순 > c가 큰 순
    priority_queue<tiii, vector<tiii>, cmp> pq;

    // 5개 단위로 자르면서 각 구간의 피로도를 구해서 튜플 만들어 (다이아로 캘 때, 철로 캘 때, 돌로 캘 때)
    for (int i = 0 ; i < minerals.size(); i += 5) {
        int diamond = 0; // 다이아몬드 곡괭이로 캤을 때 피로도
        int iron = 0; // 철 곡괭이로 캤을 때 피로도
        int stone = 0; // 돌 곡괭이로 캤을 때 피로도

        for (int j = i; j < i + 5; j++) {
            // index out of range 방지
            if (j >= minerals.size()) break;

            if (minerals[j] == "diamond") {
                diamond += 1;
                iron += 5;
                stone += 25;
            } else if (minerals[j] == "iron") {
                diamond += 1;
                iron += 1;
                stone += 5;
            } else { // minerals[j] == "stone"
                diamond += 1;
                iron += 1;
                stone += 1;
            }
        }

        if (pq.size() < pickSum) pq.push(make_tuple(diamond, iron, stone));
    }

    // 곡괭이 벡터(picks)를 순회하며 ...
    for (int i = 0; i < 3; i++) {

        // 해당 속성 곡괭이 없음
        if (picks[i] == 0) continue;

        while(picks[i]--) {
            // 모든 광물을 다 캤음
            if (pq.empty()) break;

            if (i == 0) answer += get<0>(pq.top());
            else if (i == 1) answer += get<1>(pq.top());
            else answer += get<2>(pq.top());

            pq.pop();
        }
    }

    return answer;
}