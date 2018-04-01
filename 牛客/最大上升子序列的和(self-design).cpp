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
		vector<Node>m;
		m.resize(n + 1);
		m[1].num = 1;
		m[1].sum.push_back(1);
		for (int i = 2; i <= n; i++) {
			int maxLen = 1;
			int maxIndex = i;
			for (int j = 1; j < i; j++) {
				if (v[j] < v[i])
					if (m[j].num + 1 > maxLen) {
						maxLen = m[j].num + 1;
						maxIndex = j;
					}
			}
			m[i].num = maxLen;
			m[i].sum = m[maxIndex].sum;
			m[i].sum.push_back(i);
		}
		int maxNum = m[1].num;
		int maxNumIndex = 1;
		for(int i=2;i<n;i++)
			if (m[i].num > maxNum) {
				maxNum = m[i].num;
				maxNumIndex = i;
			}
		int sum = 0;
		for (auto x : m[maxNumIndex].sum)
			sum += v[x];
		cout << sum << endl;
	}
	return 0;	
}