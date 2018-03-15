#include <iostream>
#include<vector>
using namespace std;
vector<int>tree;

int findRoot(int x) {
	if (tree[x] == -1)
		return x;
	else {
		int temp = findRoot(tree[x]);
		tree[x] = temp;
		return temp;
	}
}

int main() {
	int m, n;//n表示城镇数目，m表示路的数目
	while (cin >> n >> m) {
		tree.resize(n + 1);
		for (int i = 0; i <= n; i++)
			tree[i] = -1;
		vector<int>tree(n+1,-1);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			a = findRoot(a);
			b = findRoot(b);
			if(a!=b)tree[a] = b;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (tree[i] == -1)
				ans++;
		cout << ans - 1 << endl;
	}
	return 0;
}