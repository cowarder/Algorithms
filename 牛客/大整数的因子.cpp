#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		if (s == "-1")continue;
		vector<int>v;
		int flag;
		for (int k = 2; k <= 9; k++) {
			flag = 0;
			for (int i = 0; i < s.length(); i++) {
				flag *= 10;
				if (flag + (s[i] - '0') < k)
					flag += (s[i] - '0');
				else
					flag = (flag + (s[i] - '0')) % k;
			}
			if (flag == 0)v.push_back(k);
		}
		bool first = true;
		if (v.size() == 0)
			cout << "none";
		else
			for (int i = 0; i < v.size(); i++) {
				if (first) {
					cout << v[i];
					first = false;
				} else
					cout << " "<<v[i];
			}
		cout << endl;
	}
	return 0;
}