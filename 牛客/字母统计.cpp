#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		map<char, int>m;
		for (char i = 'A'; i <= 'Z'; i++)
			m[i] = 0;
		for (int i = 0; i<s.length(); i++)
			if (s[i] >= 'A'&&s[i] <= 'Z')
				m[s[i]]++;
		for (char i = 'A'; i <= 'Z'; i++)
			cout << char(i) << ":" << m[i] << endl;
	}
	return 0;
}