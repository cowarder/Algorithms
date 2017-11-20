#include<iostream>
using namespace std;
/*
	每一个结点指向的都是它的下面的结点
		Node 5		top
		Node 4		 |
		Node 3		 |
		Node 2		\ /
		Node 1		bottom
*/

//基于链表的栈
class Node {
public:
	int num;
	Node* next;
};

class Stack {
public:
	Stack() {
		this->top=bottom = new Node;
		this->top->next = NULL;
	}

	//判断是否为空
	bool isEmpty() {
		return this->top->next == NULL;
	}

	//出栈
	void pop() {
		if (this->top->next != NULL)
			top = top->next;
	}

	//入栈
	void push(Node* node) {
		Node* p = new Node;
		p->num = node->num;
		p->next = this->top;
		this->top = p;
	}

	//清空栈
	void makeEmpty() {
		Node* node= this->top;
		while (this->top!=this->bottom) {
			node = this->top;
			this->top = this->top->next;
			delete node;
		}
	}
private:
	Node* top;
	Node* bottom;
};

int main() {
	Stack s;
	Node* a=new Node;
	Node* b=new Node;
	a->num = 0;
	b->num = 9;
	s.push(a);
	s.push(b);
	cout << s.isEmpty() << endl;
	s.pop();
	s.pop();
	s.pop();
	cout << s.isEmpty() << endl;
	return 0;
}