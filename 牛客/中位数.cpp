#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>v;
int main() {
	int n;
	while (cin >> n) {
		if (n == 0)
			break;
		v.clear();
		v.resize(0);
		v.resize(n);
		for (int i = 0; i < v.size(); i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		if (n % 2 == 1)
			cout << v[n / 2] << endl;
		else
			cout << (v[n / 2] + v[n / 2 - 1]) / 2 << endl;
	}
	return 0;
}