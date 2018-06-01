#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class P {
public:
	string no;
	string begin;
	string end;
};

bool cmp1(P& a, P& b) {
	return a.begin < b.begin;
}

bool cmp2(P& a, P& b) {
	return a.end < b.end;
}

int main() {
	int m;
	while (cin >> m) {
		vector<P>v;
		v.resize(m);
		for (int i = 0; i < m; i++)
			cin >> v[i].no >> v[i].begin >> v[i].end;
		sort(v.begin(), v.end(), cmp1);
		cout << v[0].no << " ";
		sort(v.begin(), v.end(), cmp2);
		cout << v[v.size() - 1].no << endl ;
	}
}