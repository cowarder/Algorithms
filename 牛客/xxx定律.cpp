#include<iostream>
using namespace std;

int main() {
	int num;
	while (cin >> num) {
		if (num == 0)
			break;
		int times = 0;
		while (num != 1) {
			if (num % 2 == 0)
				num /= 2;
			else
				num = (3 * num + 1) / 2;
			times++;
		}
		cout << times << endl;
	}
	return 0;
}