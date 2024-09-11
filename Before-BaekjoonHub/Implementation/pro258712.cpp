#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

#include <iostream>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

int solution(vector<string> friends, vector<string> gifts) {
    // 주고받은 선물 정보
    unordered_map<string, unordered_map<string, int>> friends_info;
    // 선물 지수
    unordered_map<string, int> gift_score;
    // 다음 달에 받은 선물
    unordered_map<string, int> next_gift;

    // 선물을 주고 받지 않는 경우에도 0으로 값 저장
    for (int i = 0; i < friends.size(); ++i) {
        for (int j = 0; j < friends.size(); ++j) {
            if (i == j) continue;

            friends_info[friends[i]][friends[j]] = 0;
            friends_info[friends[j]][friends[i]] = 0;
        }
    }

    // 공백을 기준으로 분리하여 unordered_map에 정보 저장
    for (int i = 0; i < gifts.size(); ++i) {
        stringstream ss(gifts[i]);
        string from, to;
        ss >> from >> to;

        // 주고받은 선물 정보
        friends_info[from][to] ++;

        // 선물 지수
        gift_score[from]++;
        gift_score[to]--;
    }

    for (int i = 0; i < friends.size(); ++i) {
        string from = friends[i];
        for (auto elem : friends_info[from]) {
            string to = elem.first;

            // 주고받은 선물이 없거나, 그 수가 같은 경우
            if (friends_info[from][to] == friends_info[to][from]) {
                if (gift_score[from] > gift_score[to]) next_gift[from]++;
            } else { // 주고받은 선물의 수가 다른 경우
                if (friends_info[from][to] > friends_info[to][from]) next_gift[from]++;
            }
        }
    }

    // 가장 선물을 많이 받는 사람 계산
    vector<pair<string, int>> ret(next_gift.begin(), next_gift.end());
    sort(ret.begin(), ret.end(), cmp);

    if (ret.empty()) return 0;

    // 위의 이중 반복문에서 a-b, b-a 2번 계산되므로 2로 나눠서 최종 반환값 계산
    return ret[0].second;
}

int main() {
    cout << solution({"muzi", "ryan", "frodo", "neo"},
                     {"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"}) << "\n";

    cout << solution({"joy", "brad", "alessandro", "conan", "david"},
                     {"alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"}) << "\n";

    cout << solution({"a", "b", "c"},
                     {"a b", "b a", "c a", "a c", "a c", "c a"}) << "\n";
}