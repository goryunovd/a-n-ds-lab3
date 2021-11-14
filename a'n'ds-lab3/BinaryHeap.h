#pragma once
#ifndef BINARYHEAP_H
#include"NodeTree.h"
#include<iostream>
using namespace std;
class Heap
{
private:
	Node*root;
public:
	Heap() { this->root = NULL; };

	Heap(int data)
	{
		Node* elem = new Node(data);
		this->root = elem;
	}
	bool contains(int data)
	{
		Node* baseNode = new Node();// nodes of our Binary heap
		baseNode = this->root;
		Node* cur = new Node(data);//current node with current data should exist in heap 
		if (cur == baseNode) return true;
		else
		{
			baseNode = baseNode->getLeft();
		}
	}
	void insert(int elem)
	{

	}

	void remove(int elem)
	{

	}
	
	iterator create_dif_iterator() {}
	iterator create_bft_iterator() {}
	~Heap();

};

Heap::Heap()
{
}

Heap::~Heap()
{
}
#endif // !BINARYHEAP_H
