#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<sstream>
using namespace std;

//浮点数加法的原则是先对齐

string add(string s1, string s2) {
	int point = s1.find('.');
	int flag = 0;
	string result = "";
	for (int i = s1.length()-1; i >= 0; i--) {
		if (i == point) {
			result += '.';
			continue;
		}
		result += char('0'+((s1[i] - '0') + (s2[i] - '0') + flag) % 10);
		flag = ((s1[i]-'0') + (s2[i]-'0') + flag) / 10;
	}
	if(flag!=0)
		result += char('0' + flag);
	string r="";
	for (int i = result.size() - 1; i >= 0; i--)
		r += result[i];
	return r;
}

int main() {
	string s1,s2;
	while (cin >> s1 >> s2) {
		int pointS1 = s1.find('.');
		int pointS2 = s2.find('.');
		string intS1 = s1.substr(0, pointS1);
		string decS1 = s1.substr(pointS1 + 1);
		string intS2 = s2.substr(0, pointS2);
		string decS2 = s2.substr(pointS2 + 1);
		while (intS1.length() < intS2.length())intS1 = '0' + intS1;
		while (intS2.length() < intS1.length())intS2 = '0' + intS2;
		while (decS1.length() < decS2.length())decS1 = decS1 + '0';
		while (decS2.length() < decS1.length())decS2 = decS2 + '0';
		s1 = intS1 + '.' + decS1;
		s2 = intS2 + '.' + decS2;
		string s = add(s1, s2);
		cout << s << endl;
	}
	return 0;
}