#include<iostream>
#include<queue>
#include<functional>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		priority_queue<int, vector<int>, greater<int> > q;
		int sum = 0;
		int num;
		for (int i = 0; i < n; i++) {
			cin >> num;
			q.push(num);
		}
		while (q.size() > 1) {
			int a = q.top();
			q.pop();
			int b = q.top();
			q.pop();
			q.push(a + b);
			sum += (a + b);
		}
		cout << sum << endl;
	}
	return 0;
}