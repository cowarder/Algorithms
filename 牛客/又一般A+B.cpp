#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string conversion(int m, string s, int n) {
	int len = s.length();
	int k;
	string result = "";
	for (int i = 0; i < len;) {
		k = 0;
		for (int j = i; j < len; j++) {
			int t = (k*m + s[j] - '0') % n;
			s[j] = (k*m + s[j] - '0') / n + '0';
			k = t;
		}
		result += char(k + '0');
		while (s[i] == '0')i++;
	}
	string reverse = "";
	for (int i = result.length() - 1; i >= 0; i--)
		reverse += result[i];
	return reverse;
}

int main() {
	int a, b, m;
	while (cin >>m>>a>>b) {
		if (m == 0)
			break;
		long c = a + b;
		stringstream ss;
		ss << c;
		string s;
		ss >> s;
		string result = conversion(10, s, m);
		cout << result << endl;
	}
	return 0;
}