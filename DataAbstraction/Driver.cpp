#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include "BagInterfaceTester.h"
#include "StackInterfaceTester.h"
#include "ListInterfaceTester.h"
#include "SortUtils.h"
#include "ArrayUtils.h"
#include "SortedListInterfaceTester.h"
#include "QueueInterfaceTester.h"
#include "SL_PriorityQueue.h"
#include "BinarySearchTreeTester.h"
#include "BinaryTreeInterfaceTester.h"
#include "ArrayMaxHeap.h"
#include "DictionaryInterfaceTester.h"

#include <algorithm>
#include <chrono>

//For Checking memory leaks
#include <stdlib.h>
#include <crtdbg.h>

void arrayTest()
{
	int arr[] = { 2, 3, INT_MAX, 1 , 5, INT_MIN };

	printArray(arr, 6);
	quickSort(arr, 6);
	printArray(arr, 6);
}

int getParent(const int& index)
{
	if (index <= 0)
	{
		return -1;
	}
	if (index % 2 == 0)
	{
		return (index - 2) / 2;
	}

	return (index - 1) / 2;
}

int getParentNoRef(const int index)
{
	if (index <= 0)
	{
		return -1;
	}
	if (index % 2 == 0)
	{
		return (index - 2) / 2;
	}

	return (index - 1) / 2;
}

void testReferenceTime()
{
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	for (int i = 0; i < 100000000; i++)
	{
		getParent(i);
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	std::cout << "Time difference with reference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "\n\n";

	begin = std::chrono::steady_clock::now();
	for (int i = 0; i < 100000000; i++)
	{
		getParentNoRef(i);
	}
	end = std::chrono::steady_clock::now();

	std::cout << "Time difference with value = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "\n";
}

void testHeap()
{
	ArrayMaxHeap<int>* heap = new ArrayMaxHeap<int>();

	heap->add(5);
	heap->add(10);
	heap->add(7);
	heap->add(2);
	heap->add(11);

	std::cout << "getHeight(): returns " << heap->getHeight() << "; should be 3\n";
	std::cout << "peekTop(): returns " << heap->peekTop() << "; should be 11\n";

	delete heap;
	heap = nullptr;
}

void displayString(std::string item)
{
	std::cout << item << " ";
}

void testIterator()
{
	LinkedList<std::string>* list = new LinkedList<std::string>();
	list->insert(0, "hello");
	list->insert(1, " ");
	list->insert(2, "there");
	list->insert(3, "\nThis is a test");

	LinkedListIterator<std::string> iter = list->begin();

	while (iter != list->end())
	{
		displayString(*iter);
		++iter;
	}
	std::cout << "\nFinish\n";

	delete list;
	list = nullptr;
}

int main(int argv, char** argc)
{
	//For Checking for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); 
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	/*
	//BagInterfaceTester::TestBagInterfaceDriver();
	//printBackwards("hello", 5);
	//std::cout << isPalindrome("sdeeds");
	//std::cout << isAB("aabb");

	//ListInterfaceTester::TestListInterfaceDriver();

	//SortedListInterfaceTester::TestSortedListInterfaceDriver();

	//QueueInterfaceTester::TestQueueInterfaceDriver();

	//BinarySearchTreeTester::BSTTestDriver();
	//BinaryTreeInterfaceTester::BTTestDriver();

	//testReferenceTime();

	//testIterator();*/

	DictionaryInterfaceTester::TestDictionary();

	//For Checking for memory leaks
	_CrtDumpMemoryLeaks();
	return 0;
}