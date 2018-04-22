#include<iostream>
#include<vector>
#include<climits>
#include<numeric>
using namespace std;


/*
	将第i到第j行数组进行合并，然后求最小子序列
*/

int n, m,k;
vector<vector<int>>v;

int main() {
	while (cin >> n >> m>>k) {
		v.resize(0);
		v.clear();
		v.resize(n + 1);
		for (int i = 0; i <= n; i++)
			v[i].resize(m + 1);
		for(int i=1;i<=n;i++)
			for (int j = 1; j <= m; j++)
				cin >> v[i][j];
		int size = 0;
		int minsize = INT_MAX;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				vector<int>sv;
				sv.resize(m + 1);
				for (int k = i; k <= j; k++) {
					for (int p = 1; p <= m; p++)
						sv[p] += v[k][p];
				}
				for (int p = 1; p <= m; p++) {
					for (int q = p; q <= m; q++) {
						int area = accumulate(sv.begin() + p, sv.begin() + q+1, 0);
						int size = (j - i + 1)*(q - p + 1);
						if (size<minsize&&area>=k) {
							minsize = size;
						}
					}
				}
			}
		}
		if (minsize == INT_MAX)
			cout << -1 << endl;
		else
			cout << minsize << endl;
	}
	return 0;
}