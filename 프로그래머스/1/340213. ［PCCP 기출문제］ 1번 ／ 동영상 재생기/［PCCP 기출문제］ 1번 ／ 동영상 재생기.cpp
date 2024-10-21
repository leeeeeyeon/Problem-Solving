#include <string>
#include <vector>

#include <iostream>

using namespace std;

// "HH:MM" 형태 문자열을 HH + 60*MM로 변경
int convert(string str) {
    int hour = stoi(str.substr(0, 2));
    int minute = stoi(str.substr(3, 2));
    
    return hour*60 + minute;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int videoLenNumber = convert(video_len);
    int posNumber = convert(pos);
    int opStartNumber = convert(op_start);
    int opEndNumber = convert(op_end);
    
    // 오프닝 구간일 경우 opEndNumber로 이동
    if (opStartNumber <= posNumber && posNumber <= opEndNumber) {
        posNumber = opEndNumber;
    }
    
    for (string command : commands) {
        if (command == "prev") {
            // 현재 위치가 10초 미만인 경우 영상의 처음 위치로 이동
            if (posNumber < 10) posNumber = 0;
            else posNumber -= 10;
        } else { // command == "next"
            if (videoLenNumber - posNumber < 10) posNumber = videoLenNumber;
            else posNumber += 10;
        }
        
        // 오프닝 구간일 경우 opEndNumber로 이동
        if (opStartNumber <= posNumber && posNumber <= opEndNumber) {
            posNumber = opEndNumber;
        }
        
        cout << posNumber << endl;
    }
    
    string hh = to_string(posNumber / 60);
    if (hh.size() == 1) hh = '0' + hh;
    
    string mm = to_string(posNumber % 60);
    if (mm.size() == 1) mm = '0' + mm;
    
    answer = hh + ':' + mm;
    
    return answer;
}