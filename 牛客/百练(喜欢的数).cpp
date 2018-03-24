#include<iostream>
#include<string>
#include<string>
#include<sstream>
using namespace std;
bool isHui(string s) {
	int index = 0;
	for (index = 0; index < (s.length() / 2); index++) 
		if (s[index] != s[s.length() - 1 - index])
			break;
	
	if (index != s.length() / 2)
		return false;
	return true;
}

int getNum(string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
		sum += s[i] - '0';
	return sum;
}

int main() {
	int k;
	while (cin >> k) {
		string s;
		int sum = 0;
		for (int i = 0; i < k; i++) {
			cin >> s;
			int num;
			if (isHui(s)) {
				num = getNum(s);
				stringstream ss(num);
				ss >> s;
				if (isHui(s));
					sum++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}