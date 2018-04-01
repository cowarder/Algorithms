#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	vector<int>v;
	v.resize(10);
	while (cin >> v[0]) {
		for (int i = 1; i < 10; i++)
			cin >> v[i];
		vector<int> j;
		vector<int> o;
		for (int i = 0; i < 10; i++)
			if (v[i] % 2 == 0)
				o.push_back(v[i]);
			else
				j.push_back(v[i]);
		sort(j.begin(), j.end(), cmp);
		sort(o.begin(), o.end());
		bool first = true;
		for(int i=0;i<j.size();i++)
			if (first) {
				first = false;
				cout << j[i];
			} else
				cout << " " << j[i];
			for (int i = 0; i < o.size(); i++)
				cout << " "<<o[i];
	}
	return 0;
}