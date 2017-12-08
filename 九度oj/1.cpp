#include<iostream>
#include<algorithm>
#include<time.h>
#pragma warning(disable:4996)
using namespace std;
int main() {
	int a[100];
	int num;
	while (scanf("%d", &num) != EOF) {
		for (int i = 00; i != num; i++)
			scanf("%d", &a[i]);
		clock_t start_time = clock();
		sort(a, a + num);
		for (int i = 0; i != num; i++)
			cout << a[i];
		clock_t end_time = clock();
		cout << "程序段运行时间：" << static_cast<double> (end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
	}
	return 0;
}