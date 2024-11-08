#include <iostream>

#define MAX_N 10
using namespace std;

int arr[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        int zero = 0;
        int idx = 0;

        while (true) {
            if (zero == num && arr[idx] == 0) break;

            if (arr[idx] == 0) zero++;
            idx++;
        }

        arr[idx] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}