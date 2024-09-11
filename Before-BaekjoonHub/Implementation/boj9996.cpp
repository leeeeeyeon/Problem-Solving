#include <bits/stdc++.h>

using namespace std;

int n;
string p; // 패턴
string s; // 파일 이름
int idx; // *의 위치
string prefix, suffix; // 접두사, 접미사

int main() {

    cin >> n;
    cin >> p;
    idx = p.find('*');
    prefix = p.substr(0, idx);
    suffix = p.substr(idx + 1);
    for (int i = 0; i < n; ++i) {
        cin >> s;

        if (s.size() < prefix.size() + suffix.size()) {
            cout << "NE" << "\n";
            continue;
        }

        if (s.substr(0, prefix.size()) == prefix
            && s.substr(s.size() - suffix.size()) == suffix) {
            cout << "DA" << "\n";
        } else {
            cout << "NE" << "\n";
        }
    }
    return 0;
}
