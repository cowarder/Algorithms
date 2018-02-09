#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int>a, b;
	int x, y;
	while (cin >> x >> y) {
		a.resize(0);
		b.resize(0);
		while (x > 0) {
			a.push_back(x % 10);
			x /= 10;
		}
		while (y > 0) {
			b.push_back(y % 10);
			y /= 10;
		}
		long long result=0;
		for (int i = 0; i < a.size(); i++)
			for (int j = 0; j < b.size(); j++)
				result += a[i] * b[j];
		cout << result << endl;
	}
	return 0;
}