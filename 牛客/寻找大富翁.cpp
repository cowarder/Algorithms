#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		priority_queue<int>pq;
		int wealth;
		for (int i = 1; i <= n; i++) {
			cin >> wealth;
			pq.push(wealth);
		}
		bool first = true;
		while (m&&pq.size()!=0) {
			int wealth = pq.top();
			pq.pop();
			if (first) {
				cout << wealth ;
				first = false;
			} else
				cout << " " << wealth;
			m--;
		}
		cout << endl;
	}
	return 0;
}