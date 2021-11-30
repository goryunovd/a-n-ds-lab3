#pragma once
#ifndef NODETREE_H
#include<iostream>
class Node
{
public:
	Node(int data = 0, Node* left = NULL, Node* right = NULL, Node* prev=NULL) :data(data), left(left), right(right),prev(prev) {}
	~Node() = default;
	int getData() { return data; }
	
	void setData(int newData) { data = newData; }
	void setLeft(Node* newnleft) { left = newnleft; }
	void setRight(Node* newright) { right = newright; }
	void setPrev(Node* newprev) { prev = newprev; }


	Node* getLeft() { return left; }
	Node* getRight() { return right; }
	Node* getPrev() { return prev; }
	Node* makeNull() { return left = NULL; }

private:
	Node* left, *right, *prev;
	int data;
};


#endif // !NODETREE_H
