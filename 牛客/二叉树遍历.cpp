#include<iostream>
#include<string>
using namespace std;

string s;

class Node {
public:
	Node* left;
	Node* right;
	char data;
};

void preOrder(Node* &root, int& index) {
	if (index >= s.length())
		return;
	if (s[index] == '#') {
		index++;
		root = NULL;
	} else {
		root = new Node();
		root->data = s[index];
		index++;
		preOrder(root->left,index);
		preOrder(root->right,index);
	}
}

void inOrder(Node* root) {
	if (root == NULL)
		return;
	inOrder(root->left);
	cout << root->data<<" ";
	inOrder(root->right);
}

int main() {
	while (cin >> s) {
		Node* root =NULL;
		int index = 0;
		preOrder(root, index);
		inOrder(root);
		cout << endl;
	}
	return 0;
}