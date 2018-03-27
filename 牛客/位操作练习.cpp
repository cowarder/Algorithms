#include<iostream>
#include<string>
using namespace std;

string conversion(int m, string s, int n) {
	int len = s.length(), k;
	string result;
	for (int i = 0; i < len; ) {
		k = 0;
		for (int j = i; j < len; j++) {
			int t = (k*m + s[j] - '0') % n;
			s[j] = (k*m + s[j] - '0') / n+'0';
			k = t;
		}
		result += char(k + '0');
		while (s[i] == '0')i++;
	}
	return result;
}


int main() {
	string num1, num2;
	while (cin >> num1 >> num2) {
		num1 = conversion(10, num1, 2);
		num2 = conversion(10, num2, 2);
		while (num1.length() < 16)
			num1 = '0' + num1;
		while (num2.length() < 16)
			num2 = '0'+num2;
		bool found = false;

		for (int i = 1; i <= num2.length(); i++) {
			if (num2==num1)
				found = true;
			char c = num2[0];
			num2 = num2.substr(1);
			num2 += c;
		}
		if (found)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}