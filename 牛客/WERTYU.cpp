#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	string s1 = "WSXEDCRFVTGBYHNUJMIK,OL.P;/[']\\1234567890-=";
	string s2 = "QAZWSXEDCRFVTGBYHNUJMIK,OL.P;[]`1234567890-";
	while (getline(cin, s)) {
		string newS = "";
		for (int i = 0; i < s.length(); i++) {
			int index = s1.find(s[i]);
			if (index == -1)
				newS += s[i];
			else
				newS += s2[index];
		}
		cout << newS << endl;
	}
	return 0;
}