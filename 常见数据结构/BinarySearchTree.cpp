//BinarySearchTree

#include<iostream>
using std::cerr;
using std::endl;

class Node {
public:
	Node* left;
	Node* right;
	int num;
};

//将树清空
void makeEmpty(Node* root) {
	if (root != NULL) {
		makeEmpty(root->left);
		makeEmpty(root->right);
		delete root;
	}
}

//找到拥有特定值的结点
Node* Find(int x, Node* root) {
	if (root == NULL)
		return NULL;
	if (root->num>x)
		Find(x, root->left);
	else if (root->num<x)
		Find(x,root->right);
	else
		return root;
}

//利用递归方法找到树上的最小值
Node* FindMin(Node* root) {
	if (root == NULL)
		return NULL;
	if (root->left == NULL)
		return root;
	else
		return FindMin(root->left);
}


//这里的root是一份拷贝（局部变量）
//不使用递归的方式找到树上的最小值
Node* FindMax(Node* root) {
	if (root == NULL)
		return root;
	while (root->right != NULL)
		root = root->right;
	return temp;
}

//插入特定的结点
Node* Insert(int x, Node* root) {
	if (root == NULL) {
		root = new Node;
		//内存不足无法分配
		if (root == NULL) {
			cerr << "Out of space!" << endl;
			return;
		}
		root->num = x;
		root->left = root->right = NULL;
	}
	else {
		//小于，左子树更新
		if (x<root->num)
			root->left = Insert(x, root->left);
		//大于，右子树更新
		else if (x>root->num)
			root->right = Insert(x, root->right);
		//等于的话什么也不做，或者也可以添加一些更新操作
		//else{do something}
	}
	return root;
}

//删除特定的结点
Node* Delete(int num, Node* root) {
	if (root == NULL)
		return;
	else if (num<root->num)
		//小于，更新左子树
		root->left = Delete(num, root->left);
	else if (num>root->num)
		//大于，更新右子树
		root->right = Delete(num, root->right);
	else if (root->right&&root->left) {
		/*如果要删除结点左右子树都存在的话
		首先要找出右子树的最小结点，使此结
		点值等于最小值，然后递归地删除右子树最小值*/
		Node* temp = FindMin(root->right);
		root->num = temp->num;
		root->right = Delete(temp->num, root->right);
	}
	else {
		//有一个结点或者没有结点
		Node* temp = root;
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->right;
		delete temp;
	}
	return root;

}

int main() {

	return 0;
}