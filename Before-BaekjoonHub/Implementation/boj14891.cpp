#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

string rotate(string str, int direction) {
    string result = "";
    if (direction == 1) { // 시계 방향
        result += str[str.size()-1];
        result += str.substr(0, 7);
    } else { // direction == -1, 반시계 방향
        result += str.substr(1, 7);
        result += str[0];
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> wheels = vector<string>(4);
    for (int i = 0; i < 4; i++) {
        cin >> wheels[i];
    }

    int k; // 회전 횟수
    cin >> k;

    vector<pair<int, int>> cmds;
    for (int i = 0; i < k; i++) {
        int num, dir;
        cin >> num >> dir;

        cmds.push_back({num-1, dir});
    }

    // 맞닿은 부분
    // wheels[0][2] - wheels[1][6]
    // wheels[1][2] - wheels[2][6]
    // wheels[2][2] - wheels[3][6]

    for (auto cmd : cmds) {
        int idx = cmd.first; // 회전시킨 톱니바퀴의 번호
        int direction = cmd.second; // 방향 (1: 시계, -1: 반시계)

        vector<string> newWheels = wheels;

        // idx번 톱니바퀴 회전
        newWheels[idx] = rotate(wheels[idx], direction);

        // 왼쪽 톱니바퀴 확인
        // wheels[idx-1][2] - wheels[idx][6] 비교
        // 만약 같으면 그 이후 톱니바퀴들은 회전 X
        int curDir = direction;
        for (int i = idx; i > 0; i--) {
            if (wheels[i][6] == wheels[i-1][2]) break;

            newWheels[i-1] = rotate(wheels[i-1], -curDir);
            curDir = -curDir;
        }

        // 오른쪽 톱니바퀴 확인
        // wheels[idx][2] - wheels[idx+1][6] 비교
        // 만약 같으면 그 이후 톱니바퀴들은 회전 X
        curDir = direction;
        for (int i = idx; i < 3; i++) {
            if (wheels[i][2] == wheels[i+1][6]) break;

            newWheels[i+1] = rotate(wheels[i+1], -curDir);
            curDir = -curDir;
        }

        // wheels를 newWheels로 갱신
        wheels = newWheels;
    }

    // 총 K번 회전시킨 이후에 네 톱니바퀴의 점수의 합을 출력
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        int score = wheels[i][0] - '0';
        score *= pow(2, i);

        sum += score;
    }

    cout << sum;

    return 0;
}
