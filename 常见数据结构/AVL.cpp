#AVL.cpp

/*
	首先AVL树是二叉查找，特殊之处在于其带有平衡条件
	每个节点的左右子树的高度最多相差1
*/

/*发生不平衡情况时可以分成四类
  1.对左儿子的左子树插入
  2.对右儿子的右子树插入
  3.对左子树的右儿子插入
  4.对右儿子的左子树插入
	其中前两种视为一种情况（单旋转），而后两种视为一种情况（双旋转）
*/

class Node
{
public:
	Node* left;
	Node* right;
	int num;
	 Node();
	~ Node();
};

//k2是第一个不平衡的节点
Node* singleRoteteWithLeft(Node* k2){
	Node* k1=New Node;
	if(k1==NULL)
		return NULL;
	k1=k2->left;
	k1->right=k2;
	return k1;
}

Node* singleRoteteWithRigt(Node* k2){
	Node* k1=new Node;
	k1=k2->right;
	k1->left=k2;
	return k1;
}



