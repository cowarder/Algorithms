#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int N;
	while (cin >> N) {
		vector<int>v;
		v.resize(N + 1);
		v[1] = 1;
		v[2] = 2;
		for (int i = 3; i <= N; i++)
			v[i] = v[i - 1] + v[i - 2];
		cout << v[N] << endl;
	}
	return 0;
}