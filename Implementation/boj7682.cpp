#include <iostream>
#include <string>

using namespace std;

int countLine(string str, char target) {
    int cnt = 0;

    // 가로
    for (int i = 0; i <= 6; i += 3) {
        if (str[i] == target && str[i+1] == target && str[i+2] == target) cnt++;
    }

    // 세로
    for (int i = 0; i <= 2; i++) {
        if (str[i] == target && str[i+3] == target && str[i+6] == target) cnt++;
    }

    // 대각선
    if (str[0] == target && str[4] == target && str[8] == target) cnt++;
    else if (str[2] == target && str[4] == target && str[6] == target) cnt++;

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while (true) {
        cin >> str;

        // 문자열 "end"가 주어질 경우 종료
        if (str == "end") break;

        int x = 0;
        int o = 0;
        for (char c : str) {
            if (c == 'X') x++;
            else if (c == 'O') o++;
        }

        // 틱택토 게임에서 발생할 수 있는 최종 상태인지
        bool isValid = false;

        int xLine = countLine(str, 'X');
        int oLine = countLine(str, 'O');

        // X가 이기는 경우
        // 1. O로 이루어진 줄이 없어야 함
        // 2. 홀수 회차에만 이길 수 있음 > X가 O보다 하나 많음
        // 3. X로 이루어진 줄은 1개
        if (oLine == 0 && x == o+1 && xLine >= 1) isValid = true;

            // O가 이기는 경우
            // 1. X로 이루어진 줄이 없어야 함
            // 2. 짝수 회차에만 이길 수 있음 > X와 O의 개수가 동일해야 함
            // 3. O로 이루어진 줄은 1개
        else if (xLine == 0 && x == o && oLine >= 1) isValid = true;

            // 이긴 사람이 없는데 게임판이 가득찬 경우
            // 1. 게임판에 '.'이 없어야 함
            // 2. X로 이루어진 줄과 O로 이루어진 줄이 없어야 함
            // 3. X는 5개, O는 4개
        else if (x == 5 && o == 4 && xLine == 0 && oLine == 0) isValid = true;

        // 정답 출력
        if (isValid) cout << "valid" << '\n';
        else cout << "invalid" << '\n';
    }

    return 0;
}