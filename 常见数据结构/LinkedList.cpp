//LinkedList.cpp
#include<iostream>
using namespace std;

class Node {
public:
	int num;
	Node* next;
};

class List {
public:
	/*
	构造函数
	*/
	List() {
		head = new Node;
		head->next = NULL;
	}
	List(int* a, int len) {
		head = new Node;
		head->next = NULL;
		if (len <= 0 || a == NULL)
			return;
		Node* CopyHead = head;
		for (int i = 0; i != len; i++) {
			Node* p = new Node;
			p->num = a[i];
			p->next = NULL;
			head->next = p;
			head = head->next;
		}
		head = CopyHead;
	}

	/*
	判断是否为空链表
	*/
	bool isEmpty() {
		return head->next == NULL;
	}

	/*
	返回链表的结点数
	*/
	int size() {
		Node* p = head;
		int len = 0;
		while (p->next != NULL) {
			len++;
			p = p->next;
		}
		return len;
	}

	/*
	查找链表中与给定结点值相等的结点，返回它在链表中的位置
	*/
	int find(Node* node) {
		if (head->next == NULL || node == NULL)
			return -1;
		int position = 1;
		Node* p = head->next;
		while (p != NULL) {
			if (p->num == node->num)
				return position;
			position++;
			p = p->next;
		}
		if (p == NULL)
			return -1;
		return position;
	}

	/*
	删除结点num值相等的第一个结点
	*/
	void deleteNode(Node* node) {
		if (node == NULL || head->next == NULL)
			return;
		Node* p = head;
		while (p != NULL&&p->next->num != node->num)
			p = p->next;
		if (p == NULL)
			return;
		Node* s = p->next->next;
		delete p->next;
		p->next = s;
	}

	/*
	删除第pos位置上面的结点
	*/
	void deleteNode(int pos) {
		if (pos > size() || pos <= 0)
			return;
		int p = 0;
		Node* node = head;
		while (p < pos - 1) {
			node = node->next;
			p++;
		}
		Node* temp = node->next->next;
		delete node->next;
		node->next = temp;
	}

	/*
	在第pos个结点位置之前插入新结点
	*/
	void insertNode(Node* node, int pos) {
		if (pos > size() || pos <= 0)
			return;
		int p = 0;
		Node* n = head;
		while (p < pos - 1) {
			n = n->next;
			p++;
		}
		node->next = n->next;
		n->next = node;
	}

	/*
	打印链表
	*/
	void printList() {
		if (head->next == NULL)
			return;
		Node* p = head->next;
		while (p != NULL) {
			cout << p->num << endl;
			p = p->next;
		}
	}
private:
	Node* head;
};
int main() {
	int a[6] = { 1,2,3,4,5,6 };
	List list(a, 6);
	Node* p = new Node;
	p->next = NULL;
	p->num = 3;
	list.insertNode(p, 2);
	list.printList();
	cout << list.isEmpty() << endl;
	cout << list.size() << endl;
	return 0;
}