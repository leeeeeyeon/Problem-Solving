#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> um; // 단어별 등장 횟수

bool comp(string a, string b) {
    if (um[a] == um[b]) {
        if (a.size() == b.size()) return a < b;
        return a.size() > b.size();
    }

    return um[a] > um[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        // 길이가 M 이상인 단어들만 외움
        if (word.size() >= m) {
            if (um[word] == 0) words.push_back(word);
            um[word]++;
        }
    }

    sort(words.begin(), words.end(), comp);

    for (string word : words) cout << word << '\n';

    return 0;
}