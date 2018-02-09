#include<iostream>
using namespace std;

int main() {
	int N;
	long long num;
	while (cin >> N) {
		num = 1;
		for (int i = 1; i <= N; i++)
			num *= i;
		cout << num << endl;;
	}
	return 0;
}