#include<iostream>
#include<vector>
using namespace std;

vector<bool>v(10001);

void init() {
	for (int i = 1; i <= 10000; i++)
		v[i] = true;
	v[1] = false;
	for (int i = 2; i <= 10000; i++) {
		if (v[i] == false)
			continue;
		for (int j = i+i; j <= 10000; j += i)
			v[j] = false;
	}
}

int main() {
	init();
	int n;
	while (cin >> n) {
		bool exist = false;
		bool first = true;
		for (int i = 1; i < n; i++)
			if (v[i] == true && i % 10 == 1) {
				if (first) {
					cout << i;
					first = false;
				} else {
					cout << " " << i;
				}
				exist = true;
			}
		if (exist = false)
			cout << -1 << endl;
		else
			cout << endl;
	}
	return 0;
}