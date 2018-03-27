#include<iostream>
#include<string>
using namespace std;

bool judge(char c) {
	if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
		return true;
	return false;
}

int main() {
	string s;
	while (getline(cin, s)) {
		int start, end;
		start = end = 0;
		while (start < s.length() && end < s.length()) {
			while (end<s.length()&&(s[end]==' '||s[end]=='\t'||s[end]=='\r'))end++;
			start = end;
			if (s[start] <= 'z'&&s[start] >= 'a') {
				string news="";
				news+=char('A' + s[start] - 'a');
				s.replace(start, 1, news);
			}
			while (end<s.length()&&s[end] != ' ' && s[end] != '\t' && s[end] != '\r')end++;
		}
		cout << s << endl;
	}
	return 0;
}