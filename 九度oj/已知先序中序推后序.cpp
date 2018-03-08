#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node {
public:
	Node() {}
	Node* lchild;
	Node* rchild;
	char c;
};

int loc;		//当前结点位置
vector<Node>v(100);	//保存结点
string pre;		//先序遍历结果
string mid;		//中序遍历结果

//创建结点
Node* create() {
	v[loc].lchild = NULL;
	v[loc].rchild = NULL;
	return &v[loc++];
}

//创建树
Node* build(int s1, int e1, int s2, int e2) {
	Node* result=create();
	result->c = pre[s1];
	int index=0;
	for (int i = s2; i <= e2; i++)
		if (mid[i] == pre[s1]) {
			index = i;
			break;
		}
	//左子树不为空时
	if (index != s2)
		result->lchild = build(s1 + 1, s1 + (index - s2), s2, index-1);
	//右子树不为空时
	if (index != e2)
		result->rchild = build(s1 + (index - s2) + 1, e1, index + 1, e2);
	return result;
}

//后序遍历
void postOrder(Node* head) {
	if (head->lchild != NULL)
		postOrder(head->lchild);
	if (head->rchild != NULL)
		postOrder(head->rchild);
	cout << head->c;
}

int main() {
	loc = 0;
	while (cin >> pre >> mid) {
		int s1 = 0;
		int s2 = 0;
		int e1 = pre.length() - 1;
		int e2 = mid.length() - 1;
		Node* head = build(s1, e1, s2, e2);
		postOrder(head);
	}
	return 0;
}

