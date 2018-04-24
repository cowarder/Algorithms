#include<iostream>
#include<string>
#include<vector>
using namespace std;

string s;

void count(char sub) {
	int sum = 0;
	for (int i = 0; i <s.length(); i++)
		if (s[i] == sub)
			sum++;
	cout << sub << " " << sum << endl;
}

int main() {
	string sub;
	while (getline(cin,sub)) {
		if (sub == "#")
			break;
		getline(cin , s);
		for (char c : sub)
			count(c);
	}
	return 0;
}