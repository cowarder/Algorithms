#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	Node() {}
	Node* lchild;
	Node* rchild;
	int c;
};

vector<Node>v(100);
int loc;

Node* create() {
	v[loc].lchild = v[loc].rchild = NULL;
	return &v[loc++];
}

Node* build(Node* head, int num) {
	if (head == NULL) {
		head = create();
		head->c = num;
		return head;
	} else if (num < head->c)
		head->lchild = build(head->lchild, num);
	else if (num >= head->c)
		head->rchild = build(head->rchild, num);
	return head;
}

void mid(Node* node) {
	if (node == NULL)
		return;
	mid(node->lchild);
	cout << node->c << " ";
	mid(node->rchild);
}

int main() {
	int n;
	while (cin >> n) {
		int num;
		loc = 0;
		Node* head = NULL;
		for (int i = 0; i < n; i++) {
			cin >> num;
			head = build(head, num);
		}
		mid(&v[0]);
		cout << endl;
		v.clear();
		v.resize(100);
	}
	return 0;
}

