#include<iostream>
#include<vector>
using namespace std;


int main() {
	int a, b;
	while (cin >> a >> b) {
		int ans = 1;
		while (b != 0) {
			if (b % 2 == 1)
				ans *= a;
			b /= 2;
			a *= a;
		}
		cout << ans << endl;
	}
	return 0;
}