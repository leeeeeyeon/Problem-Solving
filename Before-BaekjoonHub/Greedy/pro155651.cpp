#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<string> a, vector<string> b) {
    if (a[0] < b[0]) return true;

    if (a[0] == b[0]) return a[1] < b[1];

    return false;
}

// a >= b + 10분일 경우 true 반환
bool compareTime(string a, string b) {
    int ah = stoi(a.substr(0, 2));
    int am = stoi(a.substr(3, 2));

    int bh = stoi(b.substr(0, 2));
    int bm = stoi(b.substr(3, 2));

    return (ah * 60 + am) >= (bh * 60 + bm + 10);
}

int solution(vector<vector<string>> book_time) {

    // 1. 시작하는 시간을 기준으로 정렬한다
    sort(book_time.begin(), book_time.end(), comp);

    // 2. Room 리스트를 만들어
    vector<vector<string>> rooms;

    // 3. book_time에 있는 원소(elem)들을 순회하며 rooms에 있는 원소(room)와 비교 ...
    for (auto elem : book_time) {
        // 처음에는 rooms가 비어있으니 무조건 객실 하나 추가
        if (rooms.empty()) {
            rooms.push_back(elem);
            continue;
        }

        bool useSameRoom = false;
        for (int i = 0; i < rooms.size(); i++) {
            vector<string> room = rooms[i];

            // 만약 elem의 시작하는 시간 >= room의 끝나는 시간 + 10분 ...
            // (= 같은 객실을 사용할 수 있음)
            if (compareTime(elem[0], room[1])) {
                // room을 elem로 갱신
                rooms[i] = elem;
                useSameRoom = true;
                break;
            }
        }

        // 같은 객실 쓸 수 없으면 객실 하나 더 추가해야 함
        if (!useSameRoom) rooms.push_back(elem);
    }

    // Room의 원소의 개수가 답이 될 것!
    return rooms.size();
}