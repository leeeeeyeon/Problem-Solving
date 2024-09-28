#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

#include <iostream>

using namespace std;

typedef tuple<string, string, string, int> tsssi;

// 정렬 기준
// 1. HEAD 사전순 (대소문자 구분 X)
// 2. NUMBER 크기순
// 3. 둘 다 동일할 경우 입력으로 들어온 순
bool comp(tsssi a, tsssi b) {
    string headA, tailA;
    string headB, tailB;
    string numberStrA, numberStrB;
    int idxA, idxB;
    
    tie(headA, numberStrA, tailA, idxA) = a;
    tie(headB, numberStrB, tailB, idxB) = b;
    
    int numberA, numberB;
    numberA = stoi(numberStrA);
    numberB = stoi(numberStrB);
    
    // 대소문자 구분 안하므로 대문자를 기준으로 정렬
    for (int i = 0; i < headA.size(); i++) {
        headA[i] = toupper(headA[i]);
    }
    for (int i = 0; i < headA.size(); i++) {
        headB[i] = toupper(headB[i]);
    }
    
    if (headA == headB) {
        if (numberA == numberB) return idxA < idxB;
        return numberA < numberB;
    }
    
    return headA < headB;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    // 1. 파일명을 head, number, tail로 구분하여 vector 만들어
    vector<tsssi> fileTuple;
    for (int i = 0; i < files.size(); i++) {
        string file = files[i];
        
        string head = "";
        string number = "";
        string tail = "";
        
        bool headDone = false;
        bool numberDone = false;
        for (int j = 0; j < file.size(); j++) {
            if (!isdigit(file[j])) {
                if (headDone) numberDone = true;
                
                if (!headDone) head += file[j]; // HEAD
                else tail += file[j]; // TAIL
            } else { // isdigit(file[j])
                if (!numberDone) {
                    headDone = true;
                    number += file[j];
                } else {
                    tail += file[j];
                }
            }
        }
        
        // cout << head << ' ' << number << ' ' << tail << endl;
        
        fileTuple.push_back(make_tuple(head, number, tail, i));
    }
    
    // 2. 정렬 기준에 맞춰 정렬
    sort(fileTuple.begin(), fileTuple.end(), comp);
    
    // 3. tuple을 string으로 만들어서 answer을 만들어
    string head, number, tail;
    int idx;
    for (auto file : fileTuple) {
        string fileName = "";
        tie(head, number, tail, idx) = file;
        
        fileName = head + number + tail;
        
        answer.push_back(fileName);
    }
    
    return answer;
}