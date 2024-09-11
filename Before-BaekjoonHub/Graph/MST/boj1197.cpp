#include <bits/stdc++.h>

using namespace std;

int parent[10'001];

int find(int x) {
    if (x==parent[x]) return x;

    int p = find(parent[x]);
    parent[x] = p;

    return parent[x];
}

void merge(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A < B) parent[B] = A;
    else parent[A] = B;
}

bool isCycle(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A == B) return true;
    return false;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e, a, b, c;
    cin >> v >> e;

    vector<pair<int, pair<int, int>>> graph = vector<pair<int, pair<int, int>>>();

    // parent 배열 초기화
    for (int i = 1; i <= v; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < e; ++i) {
        cin >> a >> b >> c; // a와 b 정점을 가중치 c로 잇는다
        graph.push_back({c, {a, b}});
    }

    // 첫 번째 원소인 간선을 기준으로 정렬됨
    sort(graph.begin(), graph.end());

    long long sum = 0;
    for (auto elem : graph) {
        if (!isCycle(elem.second.first, elem.second.second)) {
            sum += elem.first;
            merge(elem.second.first, elem.second.second);
        }
    }

    cout << sum << "\n";

    return 0;
}