#include<iostream>
#include<vector>
#include<string>
using namespace std;

string preStr, inStr;
int loc;

class Node {
public:
	Node* lchild;
	Node* rchild;
	char c;
	Node() {
		lchild = NULL;
		rchild = NULL;
	}
};
vector<Node>v(100);

Node* create() {
	v[loc].lchild = v[loc].rchild = NULL;
	return &v[loc++];
}

void postOrder(Node* head) {
	if(head->lchild!=NULL)
		postOrder(head->lchild);
	if(head->rchild!=NULL)
		postOrder(head->rchild);
	cout << head->c;
}

Node* build(int s1,int e1,int s2,int e2) {
	int index = -1;
	Node* result = create();
	result->c = preStr[s1];
	for (int i = s2; i <= e2; i++) {
		if (inStr[i] == preStr[s1]) {
			index = i;
			break;
		}
	}

	if (index != s2)//左子树不为空
		result->lchild = build(s1 + 1, s1 + index - s2, s2, index - 1);
	if (index != e2)//右子树不为空
		result->rchild = build(s1 + index - s2 + 1, e1, index + 1, e2);
	return result;
}

int main() {
	while (cin >> preStr >> inStr) {
		v.clear();
		v.resize(0);
		v.resize(100);
		loc = 0;
		int len1 = preStr.length();
		int len2 = inStr.length();
		Node* T = build(0, len1 - 1, 0, len2 - 1);
		postOrder(T);
		cout << endl;
	}
	return 0;
}