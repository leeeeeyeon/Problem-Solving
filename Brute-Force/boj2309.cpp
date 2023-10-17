#include <bits/stdc++.h>

using namespace std;

vector<int> v; // 난쟁이들의 키
vector<int> idx; // 조합을 위한 임시 배열
vector<int> ret_idx; // 일곱 난쟁이들의 인덱스
vector<int> ret; // 일곱 난쟁이들의 키

void combi(int start, vector<int> b) {
    if (b.size() == 7) {
        int sum = 0;
        for (int i: b) {
            sum += v[i];
        }
        if (sum == 100) ret_idx = b;
        return;
    }

    for (int i = start+1; i < 9; ++i) {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
}

int main() {
    // 입력
    for (int i = 0; i < 9; ++i) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    // 조합으로 서로 다른 난쟁이 7명을 뽑는 경우의 수를 구한다
    combi(-1, idx);

    for (int elem : ret_idx) {
        ret.push_back(v[elem]);
    }

    sort(ret.begin(), ret.end());

    for (int elem : ret) {
        cout << elem << "\n";
    }

    return 0;
}