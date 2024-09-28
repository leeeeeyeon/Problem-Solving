#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    string temp;
    stringstream ss(input);
    
    while(getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
    
    return result;
}


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    unordered_map<string, int> totalTime; // 차량번호, 누적 주차 시간
    unordered_map<string, int> inTime; // 차량번호, 입차 시각
    
    for (string record : records) {
        // 1. records를 공백을 기준으로 split
        vector<string> info = split(record, ' '); // {"시각", "차량번호", "IN/OUT"}
        string carNumber = info[1];
        
        // HH:MM을 HH * 60 + MM으로 관리
        vector<string> timeArr = split(info[0], ':');
        int time = stoi(timeArr[0]) * 60 + stoi(timeArr[1]);
        
        if (info[2] == "IN") {
            inTime[carNumber] = time;
        } else { // info[2] == "OUT"
            totalTime[carNumber] += (time - inTime[carNumber]);
            inTime.erase(carNumber);
        }
    }
    
    // 마지막에 출차 기록이 없으면 23:59 출차로 계산
    for (auto elem : inTime) {
        int lastTime = 23 * 60 + 59;
        string carNumber = elem.first;
        totalTime[carNumber] += (lastTime - elem.second);
    }
    
    // 차량 번호가 작은 자동차 순으로 answer 정렬
    // um이므로 미리 정렬
    vector<string> carNumbers;
    for (auto elem : totalTime) {
        carNumbers.push_back(elem.first);
    }
    sort(carNumbers.begin(), carNumbers.end());
    
    // 요금 = 기본요금 + ceil((누적 주차 시간-기본 주차 시간)/단위 시간) * 단위 요금
    // = fees[1] + ceil((누적 주차 시간-fees[0]))/fees[2]) * fees[3]
    for (string car : carNumbers) {
        double parkingFee = ceil((double)(totalTime[car]-fees[0]) / fees[2]);
        if (parkingFee < 0) parkingFee = 0;

        int result = fees[1] + parkingFee * fees[3];
        answer.push_back(result);
    }
    
    return answer;
}