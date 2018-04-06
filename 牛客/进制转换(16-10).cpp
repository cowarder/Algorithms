#include<iostream>
#include<string>
using namespace std;


int charToNum(char c) {
	if (c >= '0'&&c <= '9')
		return c - '0';
	return (c - 'A') + 10;
}

char numToChar(int num) {
	if (num >= 0 && num <= 9)
		return char(num + '0');
	return char(num - 10 + 'A');
}

string transfer(int m, string s, int n) {
	int len = s.length(), k;
	string result = "";
	for (int i = 0; i < len; ) {
		k = 0;
		for (int j = i; j < len; j++) {
			int t = (k*m + charToNum(s[j])) % n;
			s[j] = numToChar((k*m + charToNum(s[j])) / n);
			k = t;
		}
		result += numToChar(k);
		while (s[i] == '0')i++;
	}
	string newResult = "";
	for (int i = result.length()-1; i >=0; i--)
		newResult += result[i];
	return newResult;

}

int main() {
	string s;
	while (cin >> s) {
		string substr = s.substr(2);
		cout << transfer(16,substr,10) << endl;
	}
	return 0;
}