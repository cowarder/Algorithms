#include<iostream>
using namespace std;

int solve(int m, int n) {
	if (n == 1)
		return 1;
	if (m == 1 || m == 0)
		return 1;
	if (n > m)
		return solve(m, m);
	else
		return solve(m, n - 1) + solve(m - n, n);
}

int main() {
	int m, n;
	while (cin >> m >> n)
		cout << solve(m, n) << endl;
	return 0;
}