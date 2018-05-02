（1）计算联通子图的数目

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	给出城镇标号，表示这两个城镇是联通的
	求出需要再建多少条路才能使得所有城镇联通
*/

vector<int>tree;	//用来包含每个结点的父结点
int findRoot(int x) {	//寻找根节点
	if (tree[x] == -1)
		return x;
	else {
		int tmp = findRoot(tree[x]);
		tree[x] = tmp;
		return tmp;
	}
}


int main() {
	int n, e;
	while (cin >> n >> e) {
		tree.clear();
		tree.resize(n + 1);
		for (int i = 1; i <= n; i++)
			tree[i] = -1;
		int a, b;
		for (int i = 1; i <= e; i++) {
			cin >> a >> b;
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)
				tree[a] = b;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (tree[i] == -1)
				ans++;
		cout << ans - 1 << endl;
	}
	return 0;
}


（2）求出具有最多元素的联通子图的结点数量

//思路：添加一个sum数组，sum[i]表示以第i个结点为根结点的树的结点数目


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>tree;	//用来包含每个结点的父结点
vector<int>sum;		//用来表示以sum[i]为根节点的树中结点数目

int findRoot(int x) {	//寻找根节点
	if (tree[x] == -1)
		return x;
	else {
		int tmp = findRoot(tree[x]);
		tree[x] = tmp;
		return tmp;
	}
}

int main() {
	int n;
	while (cin >> n ) {
		tree.clear();
		tree.resize(101);
		sum.clear();
		sum.resize(101);
		for (int i = 1; i <= 100; i++) {
			tree[i] = -1;
			sum[i] = 1;
		}
		int a, b;
		for (int i = 1; i <= n; i++) {
			cin >> a >> b;
			a = findRoot(a);
			b = findRoot(b);
			if (a != b) {
				tree[a] = b;
				sum[b] += sum[a];
			}
		}
		int max = 0;
		for (int i = 1; i <= 100; i++)
			if (sum[i] > max)
				max = sum[i];
		cout << max << endl;
	}
	return 0;
}


（3）Kruskal算法，最小生成树
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
	题目：输入结点和边的长度，输出最小生成树的长度
	注意：要判断是否能够构成一个联通图
*/

vector<int>tree;	//用来包含每个结点的父结点
int findRoot(int x) {	//寻找根节点
	if (tree[x] == -1)
		return x;
	else {
		int tmp = findRoot(tree[x]);
		tree[x] = tmp;
		return tmp;
	}
}

class Edge {
public:
	int a, b;
	int length;
	bool operator<(Edge& e) {
		return length < e.length;
	}
};

int main() {
	int n;
	while (cin >> n) {
		if (n == 0)
			break;
		tree.resize(n + 1);
		vector<Edge>e;
		e.resize(n*(n - 1) / 2);
		for (int i = 1; i <= n; i++)
			tree[i] = -1;
		for (int i = 0; i < e.size(); i++)
			cin >> e[i].a >> e[i].b >> e[i].length;
		sort(e.begin(), e.end());
		int ans = 0;
		for (int i = 0; i < e.size(); i++) {
			int a = findRoot(e[i].a);
			int b = findRoot(e[i].b);
			if (a != b) {
				tree[a] = b;
				ans += e[i].length;
			}
		}
		int num = 0;	//判断根节点的数目，如果不为1说明这个图是不连通的
		for (int i = 1; i < tree.size(); i++)
			if (tree[i] == -1)
				num++;
		if (num != 1)
			cout << "图是不连通的" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}


（4）判断一个图是否存在环
/*
	原理：一个拓扑排序，统计每个结点的入度，每次找出来一个入度为0的结点，然后它的所有子结点
		的入度减1，然后加一个标志位，防止被访问过的结点重复被提取出来
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
	int degree;
	bool taken;
	vector<int>next;
	Node() {
		taken = false;
		degree = 0;
	}
};

int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<Node>v;
		v.resize(n);
		int s, e;
		for (int i = 1; i <= m; i++) {
			cin >> s >> e;
			v[s].next.push_back(e);
			v[e].degree++;
		}
		queue<int>q;
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (v[i].degree == 0)
				q.push(i);
		while (!q.empty()) {
			int index = q.front();
			v[index].taken = true;
			q.pop();
			ans++;
			for (int i : v[index].next)
				v[i].degree--;
			for (int i = 0; i < n; i++)
				if (v[i].degree == 0 && v[i].taken == false)
					q.push(i);
		}
		if (ans != n)
			cout << "图存在环" << endl;
		else
			cout << "图不存在环" << endl;
	}
	return 0;
}