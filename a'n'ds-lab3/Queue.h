#pragma once
#include "BinaryHeap.h"
#include<iostream>
template <class T>
class Queue
{
private:
	class Node
	{
	public:
		Node(T data = 0, Node* next = NULL) : data(data), next(next) {}
	
		T data;
		Node* next;
	};

	Node* head;
	Node* last;

public:
	Queue() 
	{
		head = NULL;
		last = NULL;
	};

	~Queue() {
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
			head = head->next;
			delete tmp;
		}
	};

	void push(T) {
		Node* tmp = new Node(data);
		if (empty())
		{
			head = tmp;
			last = tmp;
		}
		else
		{
			last->next = tmp;
			last = tmp;
		}
	};

	bool empty() {
		return head == NULL;

	};

	T front() {
		if (empty())
		{
			throw out_of_range("Empty");
		}
		else
		{
			return head->data;
		}
	};

	T back() {
		if (empty())
		{
			throw out_of_range("Empty");
		}
		else
		{
			return last->data;
		}

	};

};