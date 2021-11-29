#ifndef STACK_H
#define STACK_H
#include <iostream>

template <class T>
class Stack
{
private:
	class Node
	{
	public:
		Node(T data, Node* next=NULL):data(data),next(next) {}
		~Node() = default;
		void setNext(Node* newnext) { nex = newnext;}
		Node* getNext() { return next; }
		T getData() { return data; }
	private:
		T data;
		Node* next;
	};

	Node* head;
public:
	Stack() {
		head = NULL;
	};

	~Stack() {
		while (!empty())
		{
			pop();
		}
	};

	void pop() {
		if (empty())
		{
			throw out_of_range("No more elements");
		}
		else
		{
			Node* tmp = head;
			head = head->getNext();
			delete tmp;
		}
	};

	void push(T elem) {
		Node* tmp = new Node(data);
		Node* cur = head;
		head = tmp;
		head->setNext(cur);
		
	};

	bool empty() {
		return head == nullptr;
	};

	T top() {
		if (empty())
		{
			throw out_of_range("Empty");
		}
		else
		{
			return head->getData();
		}

	};
};

#endif