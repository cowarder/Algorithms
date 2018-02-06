#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	while (cin >> s) {
		for (int i = 3; i >= 0; i--)
			cout << s[i];
		cout << endl;
	}
	return 0;
}