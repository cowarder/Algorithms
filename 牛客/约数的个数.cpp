#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main() {
	int N;
	vector<int>v;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	for (int i = 0; i < N; i++) {
		int num = 0;
		int sq = sqrt(v[i]);
		for (int j = 1; j <sq; j++)
			if (v[i]%j == 0)
				num+=2;
		if (sq == sqrt(v[i]))
			num++;
		cout << num << endl;
	}
	return 0;
}