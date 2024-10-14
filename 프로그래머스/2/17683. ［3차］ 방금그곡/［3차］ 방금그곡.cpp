#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include <iostream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string temp;
    
    while(getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
    
    return result;
}

int calculateTime(string start, string end) {
    int sh = stoi(start.substr(0, 2));
    int sm = stoi(start.substr(3, 2));
    int eh = stoi(end.substr(0, 2));
    int em = stoi(end.substr(3, 2));
    
    return (eh * 60 + em) - (sh * 60 + sm);
}

// A#, C#, D#, F#, G#을 V, W, X, Y, Z로 변경
string convertString(string str) {
    string result = "";
    
    for (int i = 0; i < str.size(); i++) {
        if (i == str.size()-1) result += str[i];
        else if (str[i] == 'A' && str[i+1] == '#') {
            result += "U";
            i++;
        }
        else if (str[i] == 'B' && str[i+1] == '#') {
            result += "V";
            i++;
        }
        else if (str[i] == 'C' && str[i+1] == '#') {
            result += "W";
            i++;
        }
        else if (str[i] == 'D' && str[i+1] == '#') {
            result += "X";
            i++;
        }
        else if (str[i] == 'F' && str[i+1] == '#') {
            result += "Y";
            i++;
        }
        else if (str[i] == 'G' && str[i+1] == '#') {
            result += "Z";
            i++;
        }
        
        else result += str[i];
    }
    
    return result;
}

bool comp(pair<string, string> a, pair<string, string> b) {
    return a.second.size() > b.second.size();
}

string solution(string m, vector<string> musicInfos) {
    string answer;
    
    m = convertString(m);
    
    vector<pair<string, string>> results;
    for (string musicInfo : musicInfos) {
        vector<string> info = split(musicInfo, ',');
        
        string startTime = info[0];
        string endTime = info[1];
        string title = info[2];
        string music = convertString(info[3]);
        
        int time = calculateTime(startTime, endTime);
        
        // 만약 info[3]의 길이가 (끝난 시각 - 시작 시각)보다 길다면 그 길이만큼 잘라
        // 만약 info[3]의 길이가 (끝난 시각 - 시작 시각)보다 짧다면 그 길이가 될 때까지 늘려
        if (music.size() > time) music = music.substr(0, time);
        else {
            int idx = 0;
            while (music.size() < time) {
                music += music[idx];
                idx++;
            }
        }
        
        // 음악에 멜로디가 포함되어 있는 경우
        if (music.find(m) != string::npos) results.push_back({title, music});
    }
    
    if (results.size() == 0) return "(None)";
    else {
        stable_sort(results.begin(), results.end(), comp);
        return results[0].first;
    }
}