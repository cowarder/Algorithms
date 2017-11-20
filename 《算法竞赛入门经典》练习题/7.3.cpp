//主要是要根据题目要求找出数据之间内在的关系

#include<iostream>
using namespace std;

int main() {
	int k;
	cin >> k;
	float x;
	for (int y = 1; y <= 2 * k; y++) {
		x = 1.0*k*y / (y - k);
		if (x > 0 && int(x) == x)
			cout << x <<" "<<y<< endl;
	}
	return 0;
}