#include <string>
#include <vector>
#include <set>
#include <unordered_map>

#include <iostream>

using namespace std;

typedef vector<vector<string>> vvs;

// a: 제재 아이디, b: 유저 아이디
bool doesMatch(string a, string b) {
    if (a.size() != b.size()) return false;
    
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '*') continue;
        else {
            if (a[i] != b[i]) return false;
        }
    }
    
    return true;
}

int cnt = 0;
vector<string> result; // 조합하여 나오는 경우
set<set<string>> ss; // unordered_set<unordered_set<string>>은 안됨
void dfs(int depth, vvs &arr) {
    // 재귀 탈출 조건
    if (depth >= arr.size()) {
        set<string> s;
        for (string elem : result) s.insert(elem);
        
        if (s.size() == arr.size()) ss.insert(s);
        
        return;
    }
    
    for (int i = 0; i < arr[depth].size(); i++) {
        string elem = arr[depth][i];
        
        result.push_back(arr[depth][i]);
        dfs(depth+1, arr);
        result.pop_back();
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    vvs arr = vvs(banned_id.size());
    
    for (int i = 0; i < banned_id.size(); i++) {
        for (int j = 0; j < user_id.size(); j++) {
            if (doesMatch(banned_id[i], user_id[j])) {
                arr[i].push_back(user_id[j]);
            }
        }
    }
    
    dfs(0, arr);
    
    return ss.size();
}