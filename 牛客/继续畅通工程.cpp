#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
	int a, b;
	int parent;
	int weight;
    bool status;
	bool operator<(Node c) {
		return weight < c.weight;
	}
};

vector<Node>edge;
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
	int N;
	while (cin >> N) {
		if (N == 0)break;
		tree.resize(N + 1);
		for (int i = 0; i <= N; i++)
			tree[i] = -1;
		int a, b, weight;
		edge.resize((N*(N - 1)) / 2);
		for (int i = 0; i < (N*(N - 1)) / 2; i++){
            cin >> edge[i].a >>edge[i].b >>edge[i].weight>>edge[i].status;
            if(edge[i].status==1)
                edge[i].weight=0;
        }
		sort(edge.begin(), edge.end());
		int ans = 0;
		for (Node e : edge) {
			int a = findRoot(e.a);
			int b = findRoot(e.b);
			if (a != b) {
				tree[a] = b;
				ans += e.weight;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

