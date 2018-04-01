#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		vector<char>c;
		for (int i = 0; i < s.length(); i++)
			c.push_back(s[i]);
		sort(c.begin(), c.end());
		for (int i = 0; i < c.size(); i++)
			cout << c[i];
		cout << endl;
	}
	return 0;	
}