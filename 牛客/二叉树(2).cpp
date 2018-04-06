#include<iostream>
#include<queue>
using namespace std;

int main() {
	int m, n;
	while (cin >> m >> n) {
		int sum = 0;
		queue<int>q;
		q.push(m);
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			if (f <= n)
				sum++;
			if (2 * f <= n)
				q.push(2 * f);
			if (2 * f + 1 <= n)
				q.push(2 * f + 1);
		}
		cout << sum << endl;
	}
	return 0;
}