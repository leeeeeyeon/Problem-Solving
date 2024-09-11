#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end) {
    // 노드가 리프 노드인 경우
    if (start == end) return tree[node] = arr[start];

    int mid = (start + end) / 2;

    ll leftChild = init(arr, tree, node*2, start, mid);
    ll rightChild = init(arr, tree, node*2+1, mid + 1, end);

    // 구간 합을 구하는 경우
    return tree[node] = leftChild + rightChild;
}

ll query(vector<ll> &tree, int node, int start, int end, int left, int right) {
    // case 1: [start, end]와 [left, right]이 겹치지 않는 경우
    if (left > end || right < start) return 0;

    // case 2: [start, end]가 [left, right]에 포함
    if (left <= start && end <= right) return tree[node];

    // case 3, 4: 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리에서 다시 탐색 시작
    int mid = (start + end) / 2;
    ll leftChild = query(tree, node*2, start, mid, left, right);
    ll rightChild = query(tree, node*2+1, mid+1, end, left, right);
    return leftChild + rightChild;
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff) {
    // case 1: [start, end]와 [left, right]이 겹치지 않는 경우
    if (index < start || index > end) return;

    // case 2: [start, end]가 [left, right]에 포함
    tree[node] = tree[node] + diff;

    // 리프 노드가 아닌 경우에는 자식 노드도 변경해주어야 함
    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node*2, start, mid, index, diff);
        update(tree, node*2+1, mid+1, end, index, diff);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k; // 수의 개수, update 횟수, query 횟수
    cin >> n >> m >> k;

    vector<ll> arr = vector<ll>(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<ll> tree = vector<ll>(4*n);
    init(arr, tree, 1, 0, n-1);

    // a = 1: b번째 수를 c로 바꿔라
    // a = 2: b번째 수부터 c번째 수까지의 합을 구해라
    int a, b;
    ll c;
    for (int i = 0; i < m+k; ++i) {
        cin >> a >> b >> c;
        b--;

        if (a == 1) {
            update(tree, 1, 0, n-1, b, c - arr[b]);
            arr[b] = c;
        }
        else cout << query(tree, 1, 0, n-1, b, c-1) << "\n";
    }

    return 0;
}