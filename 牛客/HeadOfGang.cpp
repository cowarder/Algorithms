#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

vector<int>tree;	//父节点
vector<int>sum;		//sum[i]为根节点的集合的权重
vector<int>num;		//num[i]为根节点的集合元素数目
vector<set<int>>child;	//保存结点的子节点

class Gang {
public:
	string head;
	int num;
	bool operator<(Gang& g) {
		return head < g.head;
	}
};

int findRoot(int x) {
	if (tree[x] == -1)
		return x;
	else {
		int tmp = findRoot(tree[x]);
		tree[x] = tmp;
		return tmp;
	}
}
vector<string>letters;

int main() {
	int n, thresh;
	while (cin >> n >> thresh) {
		letters.clear();
		tree.clear();
		sum.clear();
		num.clear();
		child.clear();
		letters.resize(26);
		tree.resize(26);
		sum.resize(26);
		num.resize(26);
		child.resize(26);
		for (int i = 0; i < 26; i++) {
			tree[i] = -1;
			num[i] = 1;
			sum[i] = 0;
			child[i].insert(i);
		}
		string a, b;
		int time;
		for (int i = 1; i <= n; i++) {
			cin >> a >> b >> time;
			letters[a[0] - 'A'] = a;
			letters[b[0] - 'A'] = b;
			sum[a[0] - 'A'] += time;
			sum[b[0] - 'A'] += time;
			int x = findRoot(a[0] - 'A');
			int y = findRoot(b[0] - 'A');

			if (x != y) {
				for (int i : child[x])
					child[y].insert(i);
				tree[x] = y;
				num[y] += num[x];
			}
		}
		vector<Gang>g;
		for (int i = 0; i < 26; i++) {
			if (num[i] > 2 && tree[i] == -1) {
				int weight = -1;
				int weightIndex = -1;
				int allWeight = 0;
				for (int i : child[i]) {
					if (sum[i] > weight) {
						weight = sum[i];
						weightIndex = i;
					}
					allWeight += sum[i];
				}
				allWeight /= 2;
				if (allWeight > thresh) {
					Gang item;
					item.head = letters[weightIndex];
					item.num = num[i];
					g.push_back(item);
				}
			}
		}
		if (g.size() == 0)
			cout << 0 << endl;
		else {
			sort(g.begin(), g.end());
			cout << g.size() << endl;
			for (auto x : g)
				cout << x.head << " " << x.num << endl;
		}
	}
	return 0;
}