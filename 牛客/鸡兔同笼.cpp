#include<iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int max ,min;
		if (n % 2 == 1)
			max = min = 0;
		else {
			max = n / 2;
			min = 0;
			while (n > 0 && n % 4 != 0) {
				min++;
				n -= 2;
			}
			min += (n / 4);
		}
		cout << min << " " << max << endl;
	}
	return 0;
}