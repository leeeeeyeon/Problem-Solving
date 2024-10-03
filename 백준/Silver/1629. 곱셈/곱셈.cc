#include <iostream>
using namespace std;

long long mod(long long, long long, long long);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, c;
	cin >> a >> b >> c;
	cout << mod(a, b, c);
	return 0;
}

long long mod(long long x, long long y, long long z) {
	if (y == 1) return x%z;
	if (y % 2 != 0) return mod(x, y - 1, z) * x % z;
	else return mod(x, y / 2, z) * mod(x, y / 2, z) % z;
}