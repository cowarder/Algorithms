#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
	int a, b;
	int parent;
	int weight;
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
    int M,N;
	while (cin >> N>>M) {
		if (N == 0)break;
		tree.resize(M + 1);
		for (int i = 0; i <= M; i++)
			tree[i] = -1;
		int a, b, weight;
		edge.resize(N);
		for (int i = 0; i < N; i++)
			cin >> edge[i].a >>edge[i].b >>edge[i].weight;
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
        int sum=0;
        for(int i=1;i<=M;i++)
            if(tree[i]==-1)
                sum++;
        if(sum>1)
            cout<<"?"<<endl;
        else
		    cout << ans << endl;
	}
	return 0;
}

