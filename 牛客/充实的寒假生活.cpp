#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
	int start;
	int end;
	bool operator<(const Node& n) { return end < n.end; }
};

int main() {
	int n;
	int start, end;
	while (cin >> n) {
		vector<Node>v;
		for (int i =0 ; i < n; i++) {
			cin >> start >> end;
			Node n;
			n.start = start;
			n.end = end;
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		int pretime = -1;
		int num = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].start >= pretime) {
				num += 1;
				pretime = v[i].end;
			}
		}
		cout << num << endl;
	}
	return 0;
}