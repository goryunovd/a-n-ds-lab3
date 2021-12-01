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
	heap.insert(2);
	heap.insert(30);
	heap.insert(4);//!
	heap.insert(5);//!
	heap.insert(100);
	heap.insert(40);
	heap.insert(6);
	heap.insert(7);


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
		heap.remove(40);
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
