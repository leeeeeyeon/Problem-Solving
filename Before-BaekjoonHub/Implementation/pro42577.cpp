#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size()-1; i++) {
        string cur = phone_book[i];
        string next = phone_book[i+1];

        // 어떤 번호가 다른 번호의 접두어인 경우
        if(cur.size() <= next.size() && cur == next.substr(0, cur.size())) return false;
    }

    return true;
}