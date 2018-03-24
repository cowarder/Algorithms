#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<char>v;
vector<string>m;
void pai(int low, int high) {
	if (low == high) {
		string s;
		for (int i = 0; i <= high; i++)
			s+= v[i];
		m.push_back(s);
		//cout << endl;
	} else {
		for (int i = low; i <= high; i++) {
			swap(v[i], v[low]);
			pai(low + 1, high);
			swap(v[i], v[low]);
		}
	}
}

int main() {
	string s;
	while (cin >> s) {
		m.clear();
		m.resize(0);
		v.clear();
		v.resize(0);
		v.resize(s.length());
		for (int i = 0; i < s.length(); i++)
			v[i] = s[i];
		pai(0, v.size() - 1);
		sort(m.begin(),m.end());
		for (int i = 0; i < m.size(); i++) {
			cout << m[i] << endl;
		}
		cout << endl;
	}

	return 0;
}