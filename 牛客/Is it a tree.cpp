#include<iostream>
#include<vector>
using namespace std;

//注意第一句话开头说的是，(null.void.nothing)都算是一棵树
//（0,0）也算，无fuck说
class Node {
public:
	int indegree;
	vector<int>next;
	Node() {
		indegree = 0;
		next.clear();
		next.resize(0);
	}
};

vector<Node>v(1000);

int main() {
	int begin, end;
	int Case = 1;
	int num = 0;
	while (cin >> begin >> end) {
		if (begin == -1 && end == -1)break;
		if (begin == 0 && end == 0) {
			int count = 0;
			bool notTree = false;
			for (int i = 1; i < 1000; i++) {
				if (v[i].indegree > 1)
					notTree = true;
				if (v[i].indegree == 0 && v[i].next.size() != 0)count++;
			}
			if (num == 0)
				notTree = false;
			else if (count != 1)
				notTree = true;
			if (notTree)
				cout << "Case " << Case << " is not a tree." << endl;
			else
				cout << "Case " << Case << " is a tree." << endl;
			Case++;
			num = 0;
			v.clear();
			v.resize(1000);
		} else {
			num += 1;
			v[begin].next.push_back(end);
			v[end].indegree++;
		}

	}
	return 0;
}