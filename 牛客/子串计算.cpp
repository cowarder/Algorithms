#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		map<string, int>m;
		for (int len = 1; len < s.length(); len++) {
			for (int i = 0; i <= (s.length() - len); i++) {
				string substr = s.substr(i, len);
				m[substr]++;
			}
		}
		for (pair<string,int> s : m)
			if (s.second > 1)
				cout << s.first << " " << s.second << endl;
	}
	return 0;
}