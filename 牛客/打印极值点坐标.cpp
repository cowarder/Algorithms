#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int>v;
		v.resize(n);
		for (int i = 0; i < v.size(); i++)
			cin >> v[i];
		vector<int>index;
		if (v[0] != v[1])
			index.push_back(0);
		for (int i = 1; i < v.size() - 1; i++)
			if ((v[i] > v[i - 1] && v[i] > v[i + 1]) || (v[i] < v[i + 1] && v[i] < v[i - 1]))
				index.push_back(i);
		if (v[v.size() - 1] != v[v.size() - 2])
			index.push_back(v.size() - 1);
		bool first = true;
		for (int i = 0; i < index.size(); i++) {
			if (first) {
				first = false;
				cout << index[i];
			} else
				cout << " " << index[i];
		}
	}
	return 0;
}