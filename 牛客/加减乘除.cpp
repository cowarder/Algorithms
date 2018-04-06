#include<iostream>
using namespace std;

int calJie(int num) {
	int result = 1;
	for (int i = 1; i <= num; i++)
		result *= i;
	return result;
}

int main() {
	char op;
	int m, n;
	int result;
	while (cin >> m) {
		cin >> op;
		if (op == '!')
			result= calJie(m);
		else {
			cin >> n;
			if (op == '+')
				result = m + n;
			else if (op == '-')
				result = m - n;
			else if (op == '*')
				result = m*n;
			else if(op=='/')
				if (n == 0) {
					cout << "error" << endl;
					continue;
				} else
					result = m / n;
			else if(op=='%')
				if (n == 0) {
					cout << "error" << endl;
					continue;
				} else
					result = m % n;
		}
		cout << result << endl;
	}
	return 0;
}