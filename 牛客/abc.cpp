#include<iostream>
using namespace std;

int main() {
	for (int i = 100; i <= 999; i++) {
		int a = i / 100;
		int b = (i / 10) % 10;
		int c = i % 10;
		if (i + b * 100 + c*10+c == 532)
			cout << a<<" " << b<<" " << c << endl;
	}
	return 0;
}