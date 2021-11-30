#include <iostream>
#include "BinaryHeap.h"
#include"iterartors.h"
#include"NodeTree.h"
#include "Queue.h"
#include"stack.h"
using namespace std;
int main()
{
	Heap heap;
	Iterator* dfs_1, *dfs_2, *bfs_1, *bfs_2;
	heap.insert(1);
	heap.insert(2);
	heap.insert(3);
	heap.insert(5);
	heap.insert(666);
	heap.insert(4);
	heap.insert(87);
	dfs_1 = heap.create_dfs();
	bfs_1 = heap.create_bfs();
	cout << "around the world(heap) like daft punk\n";
	int tmp = 0;
	if (bfs_1->has_next()) {
		while (bfs_1->has_next()) { cout << bfs_1->next() << endl; }
	}
	cout << endl;
	if (dfs_1->has_next()) {
			while (dfs_1->has_next()) { cout << dfs_1->next() << endl; }
		}
		cout << endl;
		heap.remove(666);
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
}
