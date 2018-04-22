#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int>tree;	//表示点的双亲节点
vector<int>degree;	//表示节点的度

int findRoot(int x) {
	if (tree[x] == -1)
		return x;
	else {
		int tmp = findRoot(tree[x]);
		tree[x] = tmp;
		return tmp;
	}
}

int main() {
	int n, m;
	while (cin >> n) {
		if (n == 0)
			break;
		cin >> m;
		int a, b;
		set<int>s;
		tree.resize(n + 1);
		degree.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			degree[i] = 0;
			tree[i] = -1;
		}
		for (int i = 1; i <= m; i++) {
			cin >> a >> b;
			s.insert(a);
			s.insert(b);
			if (a == b)
				continue;
			degree[a]++;
			degree[b]++;
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)
				tree[a] = b;
		}
		vector<int>vv;
		for (int i : s)
			vv.push_back(i);
		int trees = 0;
		int nodes = 0;
		for (int i = 0; i < vv.size(); i++) {
			if (tree[vv[i]] == -1)
				trees++;
			if (degree[vv[i]] % 2 == 1)
				nodes++;
		}
		if (trees == 1 && nodes == 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
