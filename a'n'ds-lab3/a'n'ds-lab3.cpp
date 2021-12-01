#include <iostream>
#include "BinaryHeap.h"
#include"iterartors.h"
#include "Queue.h"
#include"stack.h"
using namespace std;
int main()
{
	Heap heap(1);
	Iterator* dfs_1, *dfs_2, *bfs_1, *bfs_2;
	heap.insert(1);
	heap.insert(2);
	heap.insert(3);
	heap.insert(4);
	heap.insert(666);
	heap.insert(4);
	heap.insert(9);
	heap.insert(7);
	/*
	time to make some ASCII
	.				666
	.			  /		\	
	.			 9		 4		
	.		   /   \   /   \
	.		  7     2  1    4 
	.		/  \
	.      1    3
	*/
	if (heap.contains(4)) {
		cout << "it exists";
	}
	else
		cout << "let's find some another node =)";
	dfs_1 = heap.create_dfs();
	bfs_1 = heap.create_bfs();
	cout << "around the world(heap) like daft punk\n";

	if (dfs_1->has_next()) {
			while (dfs_1->has_next()) { cout << dfs_1->next() << endl; }
		}
	cout << endl;
	if (bfs_1->has_next()) {
		while (bfs_1->has_next()) { cout << bfs_1->next() << endl; }
	}
		cout << endl;
		heap.remove(4);
		dfs_2 = heap.create_dfs();
		bfs_2 = heap.create_bfs();
		cout << "again around the world(heap)\n";
		if (bfs_2->has_next()) {
			while (bfs_2->has_next()) { cout << bfs_2->next() << endl; }
		}
		cout << endl;
		if (dfs_2->has_next()) {
			while (dfs_2->has_next()) { cout << dfs_2->next() << endl; }
		}
		cout << endl;
		delete dfs_1, dfs_2, bfs_1, bfs_2;
}
