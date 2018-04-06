#include<iostream>
#include<string>
using namespace std;

char transform(char c) {
	if (c >= 'A'&&c <= 'Z')
		if (c >= 'A'&c <= 'E')
			return char(c - 'A' + 'V');
		else
			return char(c - 5);
	else
		return c;
}

int main() {
	string start, end, s;
	while (getline(cin,start)) {
		if (start == "ENDOFINPUT")
			break;
		getline(cin, s);
		getline(cin, end);
		for (int i = 0; i < s.length(); i++)
			s[i] = transform(s[i]);
		cout << s << endl;
	}
	return 0;	
}