#pragma once
#include<iostream>
using namespace std;
template <class T>
class Queue
{
private:
	class elem
	{
	public:
		elem(T data = 0, elem* next = NULL) : data(data), next(next) {}
	
		T data;
		elem* next;
	};

	elem* head;
	elem* last;

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

	void pop() {//delete
		if (empty())
		{
			throw out_of_range("No more elements");
		}
		else
		{
			elem* tmp = head;
			head = head->next;
			delete tmp;
		}
	};

	void push(T data) {//add
		elem* tmp = new elem(data);
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

	T front() {//first element
		if (empty())
		{
			throw out_of_range("Empty");
		}
		else
		{
			return head->data;
		}
	};

	T back() {//last element
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