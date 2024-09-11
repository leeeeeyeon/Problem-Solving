#include <bits/stdc++.h>

using namespace std;

int l, c;
vector<char> v;
vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};

// 모음일 경우 1, 자음일 경우 0을 반환
int isVowel(char c) {
    if ((find(vowel.begin(), vowel.end(), c) != vowel.end())) return 1;
    else return 0;
}

// idx - 벡터 v에서 현재 문자의 index
// cnt - 모음의 개수
void password(string s, int idx, int cnt) {
    // 문자열의 길이가 l이 됐을 때 재귀 탈출
    if (s.size() == l) {
        // 모음이 1개 이상, 자음이 2개 이상
        if (cnt >= 1 && s.size()-cnt >= 2) cout << s << "\n";
        return;
    }

    for (int i = idx+1; i < c; ++i) {
        password(s+v[i], i, cnt + isVowel(v[i]));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> l >> c;

    for (int i = 0; i < c; ++i) {
        char temp;
        cin >> temp;
        v.push_back(temp);
    }

    // 암호를 오름차순으로 만들기 위해 정렬을 진행
    sort(v.begin(), v.end());

    for (int i = 0; i <= c-l; ++i) {
        string s;
        int cnt = isVowel(v[i]);

        password(s+v[i], i, cnt);
    }
    return 0;
}