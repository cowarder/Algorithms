#include<iostream>
#include<vector>
using namespace std;

int main() {
	int a0, a1, p, q, k;
	while (cin >> a0 >> a1 >> p >> q >> k) {
		if (k == 1)
			cout << a0 << endl;
		else if (k == 2)
			cout << a1 << endl;
		else {
			for (int i = 2; i <= k; i++) {
				int temp = ((p*a1) % 10000 + (q*a0) % 10000) % 10000;
				a0 = a1;
				a1 = temp;
			}
			cout << a1 << endl;
		}
	}
	return 0;
}