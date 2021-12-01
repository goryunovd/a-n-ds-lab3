#pragma once
#ifndef BINARYHEAP_H
#include<iostream>
//#include"NodeTree.h"
#include"iterartors.h"
#include "stack.h"
#include "Queue.h"

using namespace std;

class Heap
{
private:

class Node
{ 
public: 
	Node* left, *right, *prev; int data; 
	Node(int data = 0, Node* left = NULL, Node* right = NULL, Node* prev = NULL) :data(data), left(left), right(right), prev(prev) {}
	~Node() = default;
};
Node* root;
	int hight, numberNode;
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
			cur= root;
			stack = new Stack<Node*>();
		}
		~dfs_iterator() { delete stack; }

		bool has_next() override;

		int next() override;
		Stack<Node*>* stack;

		Node* cur;
	};

	class bfs_iterator : public Iterator
	{
	public:
		friend class BinaryHeap;

		bfs_iterator(Node* root) {
			cur = root;
			queue = new Queue<Node*>();
		}

		~bfs_iterator() { delete queue; }

		bool has_next() override;

		int next() override;


		Queue<Node*>* queue;
		Node* cur;
	};
	Iterator* create_dfs() {
		return new dfs_iterator(root);
	}

	Iterator* create_bfs() {
		bfs_iterator* new_bfs_iterator = new bfs_iterator(root);
		new_bfs_iterator->queue->push(root);
		return new_bfs_iterator;
	}
	Node* LastParent(int lay)
	{
		Node* last = root;
		int tmp_lay = lay;
		int tmp_Number = numberNode;
		if (numberNode > lay) { tmp_lay = tmp_lay * 2; }

		while (tmp_lay != 2) 
		{
			if (tmp_Number <= (tmp_lay / 2)) 
			{
				last = last->left;
				tmp_lay = tmp_lay / 2;
			}
			else
			{
				last = last->right;
				numberNode = tmp_Number - tmp_lay / 2;
				tmp_lay = tmp_lay / 2;
			}
		}
		return last;
	}
	void siftDown(Node* tmp)
	{
		if (tmp->left == NULL && tmp->right == NULL)
		{
			return;
		}
		Node* max = tmp;
		if (tmp->right == NULL)
		{
			if (tmp->data < tmp->left->data) { max = tmp->left; }
		}
		else { return; }
		if (tmp->left != NULL && tmp->right != NULL)
		{
			if ((tmp->data < tmp->right->data) || (tmp->data < tmp->left->data))
			{
				if (tmp->left->data > tmp->right->data) { max = tmp->left; }
			}
			else { max = tmp->right; }
		}
		else
		{
			return;
		}
		//swap(tmp->data, max->data);
		int swap = tmp->data;
		tmp->data = max->data;
		max->data = swap;
		siftDown(max);
	}
	void siftUp(Node* tmp) 
	{
		if (tmp->prev == NULL) { return; }
		else
		{ 
			if (tmp->data > tmp->prev->data)
			{
			//	swap(tmp->data, tmp->prev->data); 
				int swap = tmp->data;
				tmp->data = tmp->prev->data;
				tmp->prev->data = swap;
				siftUp(tmp->prev);
			}
			else
			{
				return;
			}
		}
	}
	void Heapify(Node* tmp)
	{
		if (tmp->prev == NULL) { siftDown(tmp); }
		else
		{
			if (tmp->data > tmp->prev->data)
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
		catch (out_of_range)
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
			elem = dfs->cur;
			if (dfs->next() == data) { delete dfs; return elem; }
		}
		delete dfs; throw out_of_range("Element ot found");
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
			if (cur->left == NULL) { cur->left = tmp; tmp->prev = cur; }
			else { cur->right = tmp; tmp->prev = cur; }
			Heapify(tmp);

		}
	}

	void remove(int data)
	{
		Node* deleteNode = findNode(data);
		if ((root->left == NULL) && (root->right == NULL))
		{
			delete root; root = NULL; hight = 0; numberNode = 0;
		}
		int last = 1;
		for (int i = 0; i < hight - 1; i++) { last = last * 2; }
		Node* lastElem = LastParent(last);
		if (lastElem->right != NULL)
		{
			lastElem = lastElem->right;
			lastElem->prev->right = NULL;
			numberNode--;
		}
		else
		{
			lastElem = lastElem->left;
			lastElem->prev->left = NULL;
			numberNode--;
		}
		if (numberNode == 0)
		{
			numberNode = 1;
			hight--;
			for (int i = 0; i < hight-1; i++)
			{
				numberNode = numberNode * 2;
			}
		}
		if (deleteNode == lastElem) { delete lastElem; }
		else
		{
			swap(lastElem->data, deleteNode->data);
			Heapify(deleteNode);
		}
	}

};

bool Heap::dfs_iterator::has_next() {
	return cur != NULL;
}
bool Heap::bfs_iterator::has_next() {
	return cur != NULL;
}
int Heap::bfs_iterator::next() 
{
	if (!has_next()) { throw out_of_range("No moe elements"); }
	int tmp = cur->data;
	if (cur->left != NULL) { queue->push(cur->left); }
	if (cur->right != NULL) { queue->push(cur->right); }
	queue->pop();
	try { cur = queue->front(); }
	catch (out_of_range) { cur = NULL; }
	return tmp;
}
int Heap::dfs_iterator::next() 
{
	if (!has_next()) { throw out_of_range("No more elements"); }
	int tmp = cur->data;
	if ((cur->right) != NULL) { stack->push(cur->right); }
	if ((cur->left) != NULL) { cur = cur->left; }
	else {
		try { cur = stack->top(); stack->pop(); }
		catch (out_of_range) { cur = NULL; }
	}
	return tmp;
}
#endif // !BINARYHEAP_H
