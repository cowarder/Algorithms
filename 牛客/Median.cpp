#include<iostream>
#include<vector>
using namespace std;

vector<int>v1;
vector<int>v2;

//两个有序数组按照顺序合并

int main() {
	int m, n;
	while (cin >> m) {
		v1.clear();
		v2.clear();
		v1.resize(0);
		v2.resize(0);
		v1.resize(m);
		for (int i = 0; i < m; i++)
			cin >> v1[i];
		cin >> n;
		v2.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v2[i];
		vector<int>v;
		int index1 = 0;
		int index2 = 0;
		while (index1 < m && index2 < n) {
			while (index1 < m&&index2<n&&v1[index1] <= v2[index2]) {
				v.push_back(v1[index1]);
				index1++;
			}
			while (index2 < n&&index1<m&&v2[index2] <= v1[index1]) {
				v.push_back(v2[index2]);
				index2++;
			}
		}
		while (index1 < m)
			v.push_back(v1[index1++]);
		while (index2 < n)
			v.push_back(v2[index2++]);
		if (v.size() % 2 == 1)
			cout << v[v.size() / 2] << endl;
		else
			cout << v[v.size() / 2 - 1] << endl;
	}
	return 0;
}