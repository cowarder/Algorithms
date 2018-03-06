#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	char a;
	char b;
	bool first = true;
	while (cin >> n>>a>>b) {
		if (!first) {
			cout << endl;
		}
		first = false;
		vector<vector<char>>v;
		v.resize(n);
		for (int i = 0; i < n; i++)
			v[i].resize(n);
		if (((n + 1) / 2) % 2 == 0) {
			char c = b;
			for (int i = 0; i <= ((n - 1) / 2); i++) {
				for (int j = i; j < (n - i); j++) {
					v[i][j] = c;
					v[n - i - 1][j] = c;
					v[j][i] = c;
					v[j][n - i - 1] = c;
				}
				if (c == a)
					c = b;
				else
					c = a;
			}
		}
		else {
			char c = a;
			for (int i = 0; i <= ((n - 1) / 2); i++) {
				for (int j = i; j < (n - i); j++) {
					v[i][j] = c;
					v[n - i - 1][j] = c;
					v[j][i] = c;
					v[j][n - i - 1] = c;
				}
				if (c == a)
					c = b;
				else
					c = a;
			}
		}
		if (n != 1) {
			v[0][0] = ' ';
			v[0][n - 1] = ' ';
			v[n - 1][0] = ' ';
			v[n - 1][n - 1] = ' ';
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) 
				cout << v[i][j];
			cout << endl;
		}
	}
	return 0;
}