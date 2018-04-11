#include<iostream>
#include<string>
using namespace std;

int main() {
	string s, p;
	int lens, lenp;
	while (cin >> s >> p) {
		lens = s.length();
		lenp = p.length();
		int i = 0;
		int num = 0;
		while (i <= (lens - lenp)) {
			if (s.substr(i, lenp) == p)
				num++;
			i++;
		}
		cout << num << endl;
	}
	return 0;
}