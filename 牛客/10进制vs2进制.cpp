#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<map>
using namespace std;


string conversion(int m, string  a, int n) {
	int len = a.size(), k = 0;
	string b;
	for (int i = 0; i < len;) {
		k = 0;
		for (int j = i; j <len; j++)//12345 / 2 变成  06172 那么下次跳过了数字为0的下标，从6开始 ,但是下标总是以n结束
		{
			int t = (k*m + a[j] - '0') % n;  //每次之和一位以及上一次的余数有关，向下传递一个余数
			a[j] = (k*m + a[j] - '0') / n + '0';
			k = t;
		}
		b += char(k + '0');
		while (a[i] == '0') i++;//跳过这一次产生的高位的0
	}
	return b;
}

int main() {
	string s;
	while (cin >> s) {
		s = conversion(10, s, 2);
		s = conversion(2, s, 10);
		for (int i = s.length()-1; i >= 0; i--)
			cout << s[i];
		cout << endl;
	}
	return 0;
}