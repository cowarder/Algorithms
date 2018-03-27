#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int a, b;
	while (cin >> a >> b) {
		vector<int>v1;
		vector<int>v2;
		while (a >= 1) {
			v1.push_back(a);
			a /= 2;
		}
		while (b >= 1) {
			v2.push_back(b);
			b /= 2;
		}
		int i;
		for (i = 0; i < v1.size(); i++) {
			if (find(v2.begin(), v2.end(), v1[i]) != v2.end())
				break;
		}
		cout << v1[i] << endl;
	}
	return 0;
}