#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int k;
	while (cin >> k) {
		vector<int>v;
		v.resize(k+1);
		vector<int>f;
		f.resize(k + 1);
		for (int i = 1; i <= k; i++)
			cin >> v[i];
		f[1] = 1;
		for (int i = 2; i <= k; i++) {
			vector<int>newV;
			newV.push_back(1);
			for (int j = 1; j < i; j++)
				if (v[j] >= v[i])
					newV.push_back(f[j]+1);
			f[i] = *max_element(newV.begin(),newV.end());
		}
		cout << *max_element(f.begin(),f.end()) << endl;
	}
	return 0;
}