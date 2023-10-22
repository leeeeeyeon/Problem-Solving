#include <bits/stdc++.h>

using namespace std;

string s;

int main() {

    getline(cin, s);

    for (int i = 0; i < s.length(); ++i) {
        if (65 <= s[i] && s[i] <= 77) {
            s[i] = s[i] + 13;
        }
        else if (78 <= s[i] && s[i] <= 90) {
            s[i] = 'A' + s[i] % 78;
        }
        else if (97 <= s[i] && s[i] <= 109) {
            s[i] = s[i] + 13;
        }
        else if (110 <= s[i] && s[i] <= 122) {
            s[i] = 'a' + s[i] % 110;
        }
    }

    cout << s << "\n";
    return 0;
}
