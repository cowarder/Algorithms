#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
	int num;
	vector<int> sum;
};

int main() {
	int n;
	while (cin >> n) {
		vector<int>v;
		v.resize(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		vector<int>m;
		m.resize(n + 1);
		m[1] = v[1];
		for (int i = 2; i <= n; i++) {
			int maxNum = v[i];
			for (int j = 1; j < i; j++) {
				if (v[j] < v[i])
					if (m[j] + v[i] > maxNum)
						maxNum = m[j] + v[i];
			}
			m[i] = maxNum;
		}
		cout << *max_element(m.begin(), m.end()) << endl;;
	}
	return 0;	
}