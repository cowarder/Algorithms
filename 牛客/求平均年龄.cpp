#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		double num;
		double sum = 0.0;
		for (int i = 0; i < n; i++) {
			cin >> num;
			sum += num;
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << sum / n << endl;
	}
	return 0;	
}