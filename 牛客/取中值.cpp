#include<iostream>
#include<vector>
using namespace std;

int main() {
	int len1, len2;
	while (cin >> len1 >> len2) {
		vector<int>v1, v2;
		v1.resize(len1);
		v2.resize(len2);
		for (int i = 0; i < len1; i++)
			cin >> v1[i];
		for (int i = 0; i < len2; i++)
			cin >> v2[i];
		int s1, e1, s2, e2;
		cin >> s1 >> e1;
		cin >> s2 >> e2;
		vector<int>v;
		for (int i = (s1 - 1); i <= (e1 - 1); i++)
			v.push_back(v1[i]);
		for (int i = (s2 - 1); i <= (e2 - 1); i++)
			v.push_back(v2[i]);
		if (v.size() % 2 == 1)
			cout << v[v.size() / 2] << endl;
		else
			cout << v[v.size() / 2 - 1] << endl;
	}
	return 0;
}