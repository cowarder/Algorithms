#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	vector<int> v;
	while (cin >> N) {
		v.resize(N);
		for (int i = 0; i < N; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		cout << v[N-1] << " " << v[0] << endl;
	}
	return 0;
}