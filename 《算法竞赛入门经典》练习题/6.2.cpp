//6.2

#include<iostream>
#include<vector>
#include<stack>
#include<set>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i != n; i++)
		cin >> v[i];
	stack<int> s;
	set<int>se;
	bool ok = 1;
	int index = 0;
	for (int j = 0; j < n; j++) {
		int num = v[j];
		int m=j;
		index = j;
		while (index < n-1 && v[index + 1] <= num) { index++; }
		j = index;
		for (int t = 1; t <= num; t++)
			if (se.find(t) == se.end()) {
				s.push(t);
				se.insert(t);
			}
		while (s.empty() == false && s.top() == v[m++]) { s.pop(); }
		if (s.size() != 0) {
			ok = false;
			break;
		}
	}
	if (ok)
		cout << "ok" << endl;
	else
		cout << "no" << endl;

	return 0;
}