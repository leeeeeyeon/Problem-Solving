#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define MAX_N 100
using namespace std;

int arr[MAX_N+1];
set<int> result;

int startOfCycle;

void dfs(int node, int start, vector<bool> &visited) {
    int nextNode = arr[node];
    if (visited[nextNode]) { // 사이클 발생
        startOfCycle = nextNode;
        return;
    }

    if (!visited[nextNode]) {
        visited[nextNode] = true;
        dfs(nextNode, start, visited);
        if (startOfCycle == start) result.insert(nextNode);

        if (node == startOfCycle) {
            if (startOfCycle == start) result.insert(startOfCycle);
            return;
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<bool> isInArr = vector<bool>(n+1, false);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        isInArr[arr[i]] = true;

        if (i == arr[i]) result.insert(i);
    }

    // 방향 그래프에서 사이클을 찾는다 > DFS
    for (int i = 1; i <= n; i++) {
        if (!isInArr[i]) continue;

        vector<bool> visited = vector<bool>(n+1, false);
        visited[i] = true;
        dfs(i, i, visited);
    }

    vector<int> answer = vector<int>(result.begin(), result.end());
    sort(answer.begin(), answer.end());
    cout << result.size() << '\n';
    for (int elem : result) {
        cout << elem << '\n';
    }

    return 0;
}