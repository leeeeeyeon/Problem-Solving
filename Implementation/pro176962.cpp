#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 과제 시작 시각을 기준으로 정렬
bool comp(vector<string> a, vector<string> b) {
    if (a[1] < b[1]) return true;

    return false;
}

string getEndTime(vector<string> plan) {
    string startTime = plan[1];
    string playTime = plan[2];

    int hour = stoi(startTime.substr(0, 2));
    int minute = stoi(startTime.substr(3, 2));

    minute += stoi(playTime);

    hour += minute / 60;
    minute %= 60;

    string hourString = (hour < 10) ? "0" + to_string(hour) : to_string(hour);
    string minuteString = (minute < 10) ? "0" + to_string(minute) : to_string(minute);
    return hourString + ":" + minuteString;
}

int getLeftTime(string a, string b) { // b가 a보다 먼저
    int ah = stoi(a.substr(0, 2));
    int am = stoi(a.substr(3, 2));

    int bh = stoi(b.substr(0, 2));
    int bm = stoi(b.substr(3, 2));

    return (ah * 60 + am) - (bh * 60 + bm);
}

vector<string> solution(vector<vector<string>> plans) { // [name, start, playtime]
    vector<string> answer;

    // 1. plans를 start를 기준으로 정렬한다
    sort(plans.begin(), plans.end(), comp);

    stack<pair<string, int>> stopped; // 잠시 멈춘 과제 {과목 이름, 남은 시간}

    // 2. plans를 돌며 과제 진행
    for (int i = 0; i < plans.size(); i++) {
        if (i == plans.size() - 1) { // 마지막 과제일 경우
            answer.push_back(plans[i][0]);
            // 멈추지 않고 남은 과제 계속 진행
            while (!stopped.empty()) {
                answer.push_back(stopped.top().first);
                stopped.pop();
            }

            break;
        }

        string endTime = getEndTime(plans[i]); // 현재 과목 마치는 시각
        string nextStartTime = plans[i+1][1]; // 다음 과목 시작 시각

        if (endTime == nextStartTime) { // 바로 다음 과목 시작
            answer.push_back(plans[i][0]);
        } else if (endTime > nextStartTime) { // 잠시 멈추고 다음 과제 먼저
            stopped.push({plans[i][0], getLeftTime(endTime, nextStartTime)});
        } else { // endTime < nextStartTime, 남은 시간동안 스택에 쌓인 과제 진행
            answer.push_back(plans[i][0]);

            // 다음 과목 시작까지 남은 시간 계산
            int breakTime = getLeftTime(nextStartTime, endTime);

            while (breakTime > 0 && !stopped.empty()) {
                string name = stopped.top().first; // 과목명
                int leftTime = stopped.top().second; // 해당 과목 남은 시간

                if (breakTime < leftTime) { // 남은 시간을 모두 사용 but 다 못 끝냄
                    stopped.top().second -= breakTime;
                    breakTime = 0;
                } else { // breakTime >= leftTime
                    breakTime -= leftTime;
                    answer.push_back(name);
                    stopped.pop();
                }
            }
        }
    }

    return answer;
}