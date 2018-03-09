#include<iostream>
using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b) {
		int r = a%b;
		while (r > 0) {
			a = b;
			b = r;
			r = a%b;
		}
		cout << b << endl;
	}
	return 0;
}