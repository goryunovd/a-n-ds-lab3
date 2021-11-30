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
	Node* LastParent(int lay)
	{
		Node* last = root;
		int tmp_lay = lay;
		int tmp_Number = numberNode;
		if (numberNode < lay) { tmp_lay = tmp_lay * 2; }

		while (tmp_lay != 2) 
		{
			if (tmp_Number <= (tmp_lay / 2)) 
			{
				last = last->getLeft;
				tmp_lay = tmp_lay / 2;
			}
			else
			{
				last = last->getRight;
				numberNode = tmp_Number - tmp_lay / 2;
				tmp_lay = tmp_lay / 2;
			}
		}
		return last;
	}
	void siftDown(Node* tmp)
	{
		if (tmp->getLeft == NULL && tmp->getRight == NULL)
		{
			return;
		}
		Node* max = tmp;
		if (tmp->getRight == NULL)
		{
			if (tmp->getData < tmp->getLeft.getData) { max = tmp->getLeft; }
		}
		else { return; }
		if (tmp->getLeft != NULL && tmp->getRight != NULL)
		{
			if (tmp->getData < tmp->getRight || tmp->getData < tmp->getLeft.getData)
			{
				if (tmp->getLeft.getData > tmp->getRight->getData) { max = tmp->getLeft; }
			}
			else { max = tmp->getRight; }
		}
		else
		{
			return;
		}
		swap(tmp->getData, max->getData);
		siftDown(max);
	}
	void siftUp(Node* tmp) 
	{
		if (tmp->getPrev == NULL) { return; }
		else
		{ 
			if (tmp->getData > tmp->getPrev.getData)
			{
				swap(tmp->getData, tmp->getPrev.getData); siftUp(tmp->getPrev);
			}
			else
			{
				return;
			}
		}
	}
	void Heapify(Node* tmp)
	{
		if (tmp->getPrev == NULL) { siftDown(tmp); }
		else
		{
			if (tmp->getData > tmp->getPrev.getData)
			{ siftUp(tmp); }
			else 
			{ siftDown(tmp); } 
		}
	}
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
		if (root == NULL) {
			Node* node = new Node(elem);
			root = node;
			numberNode = 1;
			hight = 1;
		}
		else 
		{
			Node* tmp = new Node(elem);
			Node* cur = root;
			int last = 1;
			numberNode++;
			for (int i = 0; i < hight - 1; i++) { last = last * 2; }
			if (last < numberNode) { numberNode = 1; hight++; last =last* 2; }
			cur = LastParent(last);
			if (cur->getLeft == NULL) { cur->getLeft = tmp; tmp->getPrev = cur; }
			else { cur->getRight = tmp; tmp->getPrev = cur; }
			Heapify(tmp);

		}
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
