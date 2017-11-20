//先序，中序，后序遍历输出结点值，计算树的左右子树权值和是否相同


#include<iostream>
#include<vector>
#include<regex>
#include<sstream>
using namespace std;

class Node {
public:
	Node();
	int num;
	Node* left;
	Node* right;
};

Node::Node() {
	num = -1;
	left = nullptr;
	right = nullptr;
}

void preTraverse(Node* n) {
	if (n != nullptr) {
		cout << n->num << endl;
		preTraverse(n->left);
		preTraverse(n->right);
	}
}

void midTraverse(Node* n) {
	if (n != nullptr) {
		preTraverse(n->left);
		cout << n->num << endl;
		preTraverse(n->right);
	}
}

void backTraverse(Node* n) {
	if (n != nullptr) {
		preTraverse(n->left);
		preTraverse(n->right);
		cout << n->num << endl;
	}
}

int getWeight(Node* n) {
	int m =0;
	if (n != nullptr) {
		m += n->num;
		m+=getWeight(n->left);
		m+=getWeight(n->right);
	}
	return m;
}

int main() {
	string s;
	Node *head=new Node();
	while (cin >> s) {											//构造树
		if (s != "()") {
			const regex pattern("\\(([0-9]+)?,(\\w+)?\\)");
			match_results<string::const_iterator> result;		//返回的是一个String数组
			bool valid = regex_match(s, result, pattern);

			string numStr = result[1];			//提取结点数值
			string pos = result[2];			//提取结点位置

			stringstream ss(numStr);
			int num;
			ss >> num;
			if (pos == "") {
				head->num = num;		//数字转换为字符串
				continue;
			}
			Node* preNode=head;
			for (int j = 0; j != pos.length(); j++) {
				if (pos[j] == 'L') {
					if (preNode->left == nullptr) {
						Node* l = new Node();
						preNode->left = l;
						preNode = preNode->left;

					} else {
						preNode = preNode->left;
					}
				}
				else if (pos[j] == 'R') {
					if (preNode->right == nullptr) {
						Node* r = new Node();
						preNode->right = r;
						preNode = preNode->right;
					} else 
						preNode = preNode->right;
				}
				if (j == (pos.length() - 1))
					preNode->num = num;
			}
		}
		else if(s=="()")
			break;
	}
	string answer = getWeight(head->left) == getWeight(head->right) ? "balanced" : "not balanced";
	cout << answer << endl;
	return 0;
}