#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main() {
	string num;
	while (cin >> num) {
		int weight = 1;
		long result = 0;
		while (num.length() > 0) {
			result += (num[num.length() - 1] - '0')*(pow(2, weight) - 1);
			weight++;
			num = num.substr(0, num.length() - 1);
		}
		cout << result << endl;
	}
	return 0;
}