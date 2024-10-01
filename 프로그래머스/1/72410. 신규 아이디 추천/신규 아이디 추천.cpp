#include <string>
#include <vector>

#include <iostream>

using namespace std;

string solution(string new_id) {    
    // 1. 모든 대문자를 대응되는 소문자로 치환
    for (int i = 0; i < new_id.size(); i++) {
        if (isalpha(new_id[i])) new_id[i] = tolower(new_id[i]);
    }
    
    // 2. 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거
    string temp = "";
    for (int i = 0; i < new_id.size(); i++) {
        if (isalpha(new_id[i]) || isdigit(new_id[i]) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            temp += new_id[i];
        }
    }
    new_id = temp;
    
    // 3. 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
    temp = "";
    bool countDot = false; // 앞에 '.'이 연속해서 나왔는지 여부
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] == '.') {
            if (!countDot) temp += new_id[i];
            countDot = true;
        } else {
            temp += new_id[i];
            countDot = false;
        }
    }
    
    new_id = temp;
    
    // 4. 마침표(.)가 처음이나 끝에 위치한다면 제거
    if (new_id[0] == '.') new_id = new_id.substr(1, new_id.size()-1);
    else if (new_id[new_id.size()-1] == '.') new_id = new_id.substr(0, new_id.size()-1);
    
    // 5. 빈 문자열이라면, new_id에 "a"를 대입
    if (new_id.size() == 0) new_id += 'a';
    
    // 6. 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거
    if (new_id.size() >= 16) {
        new_id = new_id.substr(0, 15);
    }
    
    // 6-1. 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거
    if (new_id[new_id.size()-1] == '.') {
        new_id = new_id.substr(0, new_id.size()-1);
    }
    
    // 7. 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙임
    if (new_id.size() <= 2) {
        while (new_id.size() < 3) new_id += new_id[new_id.size()-1];
    }
    
    return new_id;
}