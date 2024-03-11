#include <bits/stdc++.h>

using namespace std;

// 세그먼트 트리 생성
int initMin(int start, int end, int node, vector<int> &tree, vector<int> &a) {
    if (start == end) return tree[node] = a[start];

    int mid = (start + end) / 2;

    int left = node * 2;
    int right = node * 2 + 1;

    // 부모 노드 = 왼쪽 자식 노드의 데이터 + 오른쪽 자식 노드의 데이터
    return tree[node] = min(initMin(start, mid, left, tree, a), initMin(mid+1, end, right, tree, a));
}

int initMax(int start, int end, int node, vector<int> &tree, vector<int> &a) {
    if (start == end) return tree[node] = a[start];

    int mid = (start + end) / 2;

    int left = node * 2;
    int right = node * 2 + 1;

    // 부모 노드 = 왼쪽 자식 노드의 데이터 + 오른쪽 자식 노드의 데이터
    return tree[node] = max(initMax(start, mid, left, tree, a), initMax(mid+1, end, right, tree, a));
}

int findMin(int start, int end, int node, int left, int right, vector<int> &tree) {
    // 범위 밖
    if (left > end || right < start) return INT_MAX;

    // 범위 안
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;

    return min(findMin(start, mid, node*2, left, right, tree), findMin(mid+1, end, node*2+1, left, right, tree));
}

int findMax(int start, int end, int node, int left, int right, vector<int> &tree) {
    // 범위 밖
    if (left > end || right < start) return INT_MIN;

    // 범위 안
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;

    return max(findMax(start, mid, node*2, left, right, tree), findMax(mid+1, end, node*2+1, left, right, tree));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> minTree = vector<int>(4*n);
    vector<int> maxTree = vector<int>(4*n);
    vector<int> arr = vector<int>(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    initMin(0, n-1, 1, minTree, arr);
    initMax(0, n-1, 1, maxTree, arr);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        int mn = findMin(0, n-1, 1, a-1, b-1, minTree);
        int mx = findMax(0, n-1, 1, a-1, b-1, maxTree);

        cout << mn << " " << mx << "\n";
    }
}