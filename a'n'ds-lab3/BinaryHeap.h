#pragma once
#ifndef BINARYHEAP_H
#include<iostream>
#include"NodeTree.h"
#include"iterartors.h"
#include "stack.h"
#include "Queue.h"

using namespace std;

class Heap
{
private:
	friend class Node;
	Node* root; int hight, numberNode;
public:
	Heap() {root = NULL; hight = 0; numberNode = 0; }

	Heap(int data)
	{
		Node* elem = new Node(data);
		root = elem;
		hight = 1; numberNode = 1;
	}

	class dfs_iterator : public Iterator
	{
	public:
		friend class BinaryHeap;

		dfs_iterator(Node* root) {
			current = root;
			stack = new Stack<Node*>();
		}
		~dfs_iterator() { delete stack; }

		bool has_next() override;

		int next() override;

	

		Stack<Node*>* stack;

		Node* current;
	};

	class bfs_iterator : public Iterator
	{
	public:
		friend class BinaryHeap;

		bfs_iterator(Node* root) {
			current = root;
			queue = new Queue<Node*>();
		}

		~bfs_iterator() { delete queue; }

		bool has_next() override;

		int next() override;

	private:
		Queue<Node*>* queue;
		Node* current;
	};

	bool contains(int data)
	{
		try
		{
			findNode(data);
			return true;
		}
		catch (invalid_argument)
		{
			return false;
		}
	}
	Node* findNode(int data)
	{
		Node* elem = NULL;
		dfs_iterator* dfs = new dfs_iterator(root);
		while (dfs->has_next()) 
		{
			elem = dfs->current;
			if (dfs->has_next() == data) { delete dfs; return elem; }
		}
		delete dfs; throw invalid_argument("Element ot found");
	}
	void insert(int elem)
	{

	}

	void remove(int elem)
	{

	}

};

bool Heap::dfs_iterator::has_next() {
	return current != NULL;
}
bool Heap::bfs_iterator::has_next() {
	return current != NULL;
}
int Heap::bfs_iterator::next() 
{
	if (!has_next()) { throw out_of_range("No moe elements"); }
	int tmp = current->getData;
	if (current->getLeft != NULL) { queue->push(current->getLeft); }
	if (current->getRight != NULL) { queue->push(current->getRight); }
	queue->pop();
	try { current = queue->front(); }
	catch (out_of_range) { current = NULL; }
	return tmp;
}
int Heap::dfs_iterator::next() 
{
	if (!has_next()) { throw out_of_range("No more elements"); }
	int tmp = current->getData;
	if (current->getRight != NULL) { stack->push(current->getRight); }
	if (current->getLeft != NULL) { current = current->getLeft; }
	else {
		try { current = stack->top(); }
		catch (out_of_range) { current = NULL; }
	}
	return tmp;
}
#endif // !BINARYHEAP_H
