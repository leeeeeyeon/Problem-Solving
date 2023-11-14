#include <bits/stdc++.h>

using namespace std;

string name;
map<char, int> mp; // default가 오름차순 정렬
string p;
string ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> name;

    for (auto c : name) {
        mp[c]++;
    }

    int cnt = 0;
    char odd = 0;
    // 홀수인 알파벳이 2개 이상이면 I'm Sorry Hansoo 출력
    for (auto elem : mp) {
        if (elem.second % 2 != 0) {
            cnt ++;
            odd = elem.first;
        }
    }

    // 홀수인 알파벳이 2개 이상인 경우
    if (cnt > 1) {
        cout << "I'm Sorry Hansoo" << "\n";
        return 0;
    }

    for (auto elem : mp) {
        p.append(elem.second/2, elem.first);
    }

    ret += p;

    if (odd) ret += odd;

    reverse(p.begin(), p.end());
    ret += p;

    cout << ret << "\n";
    return 0;
}

/*
 * 피드백 1) map에서는 첫 번째 원소를 기준으로 오름차순으로 정렬된다
 * 피드백 2) 문자열의 크기가 짝수일 경우, 알파벳 순으로 팰린드롬의 앞을 만들고 문자열 뒤집어서 합친다
 * 피드백 3) 문자열의 크기가 홀수일 경우, 갯수가 홀수인 알파벳이 2개 이상이면 I'm Sorry Hansoo
 * 피드백 4) 문자열의 크기가 홀수일 경우, 갯수가 홀수인 알파벳이 1개라면 피드백 2에서 앞을 만들고, 알파벳 붙이고, 뒤집은 문자열을 붙인다
 * 피드백 5) string을 이어붙일 때는 +=, append(횟수, 문자), push_back()을 쓸 수 있다
 * */