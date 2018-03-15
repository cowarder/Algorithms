#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;

class Edge {
public:
	int a, b;
	double weight;
	bool operator<(Edge c) {
		return weight < c.weight;
	}
};

class Node {
public:
	double x;
	double y;
};

vector<Edge>edge;
vector<int>tree;

int findRoot(int x) {
	if (tree[x] == -1)return x;
	else {
		int temp = findRoot(tree[x]);
		tree[x] = temp;
		return temp;
	}
}


int main() {
	int n;
	while (cin >> n) {
		vector<Node>v;
		v.resize(n);
		tree.resize(n + 1);
		edge.clear();
		edge.resize(0);
		for (int i = 0; i < n; i++)
			cin >> v[i].x >> v[i].y;
		for (int i = 0; i <= n; i++)
			tree[i] = -1;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				double distance = sqrt((v[i].x - v[j].x)*(v[i].x - v[j].x) + (v[i].y - v[j].y)*(v[i].y - v[j].y));
				Edge e;
				e.a = i + 1;
				e.b = j + 1;
				e.weight = distance;
				edge.push_back(e);
			}
		}
		sort(edge.begin(), edge.end());
		double dis = 0.0;
		for (Edge e : edge) {
			int a = findRoot(e.a);
			int b = findRoot(e.b);
			if (a != b) {
				tree[a] = b;
				dis += e.weight;
			}
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << dis << endl;

	}
	return 0;
}

