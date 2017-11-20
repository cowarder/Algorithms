//6.7

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
	Node* t = head;
	/*while (t != nullptr) {
		cout << t->num << endl;
		t = t->right;
	}*/

	vector<Node*> oldNodes;
	vector<Node*> newNodes;
	vector<int> Nodes;
	oldNodes.push_back(head);
	Nodes.push_back(head->num);
	while (true) {
		for (Node* oldNode : oldNodes) {
			if (oldNode->left != nullptr)
				newNodes.push_back(oldNode->left);
			if (oldNode->right != nullptr)
				newNodes.push_back(oldNode->right);
		}
		if (newNodes.size() == 0)
			break;
		for (Node* n : newNodes) {
			Nodes.push_back(n->num);				//放在总的数组里面存储出来
		}
		oldNodes = newNodes;
		newNodes.resize(0);					//重置数组
	}
	for (int n : Nodes)
		cout << n << endl;
	return 0;
}