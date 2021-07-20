#pragma once

#include <iostream>
#include <stack>
#include "LinkedStack.h"
#include "ArrayStack.h"

class StackInterfaceTester
{
private:
	static void displayStack(StackInterface<int>* stackPtr)
	{
		std::stack<int> queue;
		
		while (!stackPtr->isEmpty())
		{
			int num = stackPtr->peek();
			std::cout << num << " ";
			stackPtr->pop();
			queue.push(num);
		}

		while (!queue.empty())
		{
			stackPtr->push(queue.top());
			queue.pop();
		}

		std::cout << "\n\n";
	}

	static void stackTester(StackInterface<int>* stackPtr)
	{
		std::cout << "isEmpty: returns " << stackPtr->isEmpty()
			<< "; should be 1 (true)\n";
		int items[] = { 1, 2, 3, 4, 5, 6 };
		std::cout << "Add 6 items to the bag: \n";
		for (int i = 0; i < 6; i++)
		{
			stackPtr->push(items[i]);
		}
		displayStack(stackPtr);
		std::cout << "peek: returns " << stackPtr->peek() << "; should be 6\n";
		std::cout << "isEmpty: returns " << stackPtr->isEmpty()
			<< "; should be 0 (false)\n";
		std::cout << "Try to push another entry: push(7) returns "
			<< stackPtr->push(7) << "; should be 1 (true)\n";
		std::cout << "peek: returns " << stackPtr->peek() << "; should be 7\n";
		std::cout << "Try to pop entry: returns " << stackPtr->pop() << "; should be 1 (true)\n";
		std::cout << "peek: returns " << stackPtr->peek() << "; should be 6\n";
		std::cout << "Try to pop entry: returns " << stackPtr->pop() << "; should be 1 (true)\n";
		std::cout << "peek: returns " << stackPtr->peek() << "; should be 5\n";
		std::cout << "Try to pop entry: returns " << stackPtr->pop() << "; should be 1 (true)\n";
		std::cout << "peek: returns " << stackPtr->peek() << "; should be 4\n\n";
		displayStack(stackPtr);
		std::cout << "Try to pop entry: returns " << stackPtr->pop() << "; should be 1 (true)\n";
		std::cout << "Try to pop entry: returns " << stackPtr->pop() << "; should be 1 (true)\n";
		std::cout << "Try to pop entry: returns " << stackPtr->pop() << "; should be 1 (true)\n";
		std::cout << "Try to pop entry: returns " << stackPtr->pop() << "; should be 1 (true)\n";
		std::cout << "Try to pop entry: returns " << stackPtr->pop() << "; should be 0 (false)\n";
		std::cout << "isEmpty: returns " << stackPtr->isEmpty()
			<< "; should be 1 (true)\n";
	}

public:
	static void TestStackInterfaceDriver()
	{
		StackInterface<int>* stackPtr = nullptr;
		char userChoice;
		std::cout << "Enter 'A' to test the array-based implementation\n";
		std::cout << "Enter 'L' to test the linked-based implementation\n";
		std::cin >> userChoice;

		if (toupper(userChoice) == 'A')
		{
			stackPtr = new ArrayStack<int>();
			std::cout << "Testing the Array-Based stack\n\n";
		}
		else
		{
			stackPtr = new LinkedStack<int>();
			std::cout << "Testing the Linked-Based stack\n\n";
		}

		std::cout << "The initial stack is empty\n";
		stackTester(stackPtr);
		delete stackPtr;
		stackPtr = nullptr;
		std::cout << "All done!\n";
	}
};