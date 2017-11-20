#include<iostream>
using namespace std;
/*
	ÿһ�����ָ��Ķ�����������Ľ��
		Node 5		top
		Node 4		 |
		Node 3		 |
		Node 2		\ /
		Node 1		bottom
*/

//���������ջ
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

	//�ж��Ƿ�Ϊ��
	bool isEmpty() {
		return this->top->next == NULL;
	}

	//��ջ
	void pop() {
		if (this->top->next != NULL)
			top = top->next;
	}

	//��ջ
	void push(Node* node) {
		Node* p = new Node;
		p->num = node->num;
		p->next = this->top;
		this->top = p;
	}

	//���ջ
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