#include <vector>

#define NODE_MAX 1'000'001

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    // {생성한 정점의 번호, 도넛 모양 그래프의 수, 막대 모양 그래프의 수, 8자 모양 그래프의 수}
    vector<int> answer = {0, 0, 0, 0};

    // 들어오는 간선의 수
    vector<int> in = vector<int>(NODE_MAX, 0);
    // 나가는 간선의 수
    vector<int> out = vector<int>(NODE_MAX, 0);

    for (auto edge : edges) {
        // [a, b]일 때, a에서 나가는 간선이 1개 증가하고 b로 들어오는 간선이 1개 증가
        in[edge[1]]++;
        out[edge[0]]++;
    }

    // HINT: 나가는 간선의 수와 들어오는 간선의 수를 이용해서 구하자
    // 생성한 정점: 나가는 간선 2개 이상, 들어오는 간선 없음
    // 막대: 나가는 간선 1개, 들어오는 간선 1개 이상
    // 8자: 나가는 간선 2개, 들어오는 간선 2개 이상
    // 도넛: (생성된 정점)의 나가는 수 - (막대) - (8자)

    for(int i=1; i< NODE_MAX; i++) {
        // 생성한 정점
        if (in[i] == 0 && out[i] >= 2) answer[0] = i;

            // 막대
        else if (in[i] >= 1 && out[i] == 0) answer[2]++;

            // 8자
        else if (in[i] >= 2 && out[i] == 2) answer[3]++;
    }

    // 도넛
    answer[1] = out[answer[0]] - answer[2] - answer[3];


    return answer;
}