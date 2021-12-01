#include "pch.h"
#include "CppUnitTest.h"
#include"..\a'n'ds-lab3\BinaryHeap.h"
#include"..\a'n'ds-lab3\iterartors.h"
#include"..\a'n'ds-lab3\Queue.h"
#include"..\a'n'ds-lab3\stack.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test_iterators)
		{
			Heap heap(1);
			Iterator *dfs, *bfs;
			heap.insert(1);
			heap.insert(2);
			heap.insert(3);
			heap.insert(4);
			heap.insert(666);
			heap.insert(4);
			heap.insert(9);
			heap.insert(7);
			int arrayDfs[9], i = 0;
			dfs = heap.create_dfs();
			bfs = heap.create_bfs();
			if (dfs->has_next()) {
				while (dfs->has_next()) { arrayDfs[i++] = dfs->next(); }
			}
			int arrayBfs[9]; i = 0;
			if (bfs->has_next()) {
				while (bfs->has_next()) { arrayBfs[i++] = bfs->next(); }
			}
			Assert::AreEqual(666, arrayDfs[0]);
			Assert::AreEqual(9, arrayDfs[1]);
			Assert::AreEqual(7, arrayDfs[2]);
			Assert::AreEqual(1, arrayDfs[3]);
			Assert::AreEqual(3, arrayDfs[4]);
			Assert::AreEqual(2, arrayDfs[5]);
			Assert::AreEqual(4, arrayDfs[6]);
			Assert::AreEqual(1, arrayDfs[7]);
			Assert::AreEqual(4, arrayDfs[8]);

			Assert::AreEqual(666, arrayBfs[0]);
			Assert::AreEqual(9, arrayBfs[1]);
			Assert::AreEqual(4, arrayBfs[2]);
			Assert::AreEqual(7, arrayBfs[3]);
			Assert::AreEqual(2, arrayBfs[4]);
			Assert::AreEqual(1, arrayBfs[5]);
			Assert::AreEqual(4, arrayBfs[6]);
			Assert::AreEqual(1, arrayBfs[7]);
			Assert::AreEqual(3, arrayBfs[8]);
			delete dfs, bfs;
			}
		TEST_METHOD(Test_insert_remove_contains)
		{
			Heap heap(1), empyHeap;
			Iterator* dfs,*bfs;
			heap.insert(1);
			heap.insert(2);
			heap.insert(3);
			heap.insert(4);
			heap.insert(666);
			heap.insert(4);
			heap.insert(9);
			/*
			time to make some ASCII
			.				666 		after insert(7)		666		after remove(3)		666
			.			  /		\						  /		\					  /  	\
			.			 9		 4						 9		 4					 9		 4
			.		   /   \   /   \				   /   \   /   \				/ \     / \
			.		  3     2  1    4				  3     2  1    4			   2   2   1   4
			.		/								/  \						  /
			.      1							   1	2						 1 
			*/
			Assert::IsFalse(heap.contains(7));
			Assert::IsTrue(heap.contains(666));
			heap.insert(2);
			Assert::IsTrue(heap.contains(2));
			heap.remove(3);
			Assert::IsFalse(heap.contains(3));
			Assert::IsTrue(heap.contains(2)); Assert::IsTrue(heap.contains(1));
		}
		TEST_METHOD(Test_stack)
		{
			Stack<int> stack;
			for (int i = 0; i < 10; i++)
			{
				stack.push(i);
			}
			Assert::IsFalse(stack.empty());
			for (int i = 9; i >= 0; i--) { Assert::AreEqual(stack.top(), i); stack.pop(); }
			Assert::IsTrue(stack.empty());
			bool check = 1;
			try
			{
				stack.top();
			}
			catch(std::out_of_range)
			{
				check = 0;
			}
			Assert::IsFalse(check);
		}
		TEST_METHOD(Test_queue)
		{
			Queue<int> queue;
			for(int i=0;i<10;i++)
			{
				queue.push(i);
			}
			Assert::IsFalse(queue.empty());
			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(queue.front(), i); queue.pop();
			}
			Assert::IsTrue(queue.empty());
			bool check = 1;
			try
			{
				queue.front();
			}
			catch (std::out_of_range)
			{
				check = 0;
			}
			Assert::IsFalse(check);
		}
	};
}