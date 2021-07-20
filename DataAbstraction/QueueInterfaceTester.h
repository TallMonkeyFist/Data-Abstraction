#pragma once

#include "ListQueue.h"
#include "LinkedQueue.h"
#include "ArrayQueue.h"
#include <iostream>
#include <queue>

class QueueInterfaceTester
{
private:
	static void printQueue(QueueInterface<int>* queuePtr)
	{
		std::cout << "\n";
		std::queue<int>* tempPtr = new std::queue<int>();

		while (!queuePtr->isEmpty())
		{
			tempPtr->emplace(queuePtr->peekFront());
			queuePtr->dequeue();
		}
		while (!tempPtr->empty())
		{
			std::cout << tempPtr->front() << " ";
			queuePtr->enqueue(tempPtr->front());
			tempPtr->pop();
		}
		std::cout << "\n\n";
		delete tempPtr;
		tempPtr = nullptr;
	}

	static void printAndClearQueue(QueueInterface<int>* queuePtr)
	{
		std::cout << "\nClearing and printing contents of queue\n\n";
		std::queue<int>* tempPtr = new std::queue<int>();

		while (!queuePtr->isEmpty())
		{
			tempPtr->emplace(queuePtr->peekFront());
			std::cout << "dequeue(): returns " << queuePtr->dequeue() << "; should be 1 (true)\n";
		}
		while (!tempPtr->empty())
		{
			std::cout << tempPtr->front() << " ";
			tempPtr->pop();
		}
		std::cout << "\n\n";
		delete tempPtr;
		tempPtr = nullptr;
	}

	static void queueTester(QueueInterface<int>* queuePtr, char userChoice)
	{
		std::cout << "enqueue(5): returns " << queuePtr->enqueue(5) << "; should be 1 (true)\n";
		std::cout << "enqueue(1): returns " << queuePtr->enqueue(1) << "; should be 1 (true)\n";
		std::cout << "enqueue(3): returns " << queuePtr->enqueue(3) << "; should be 1 (true)\n";
		std::cout << "dequeue(): returns " << queuePtr->dequeue() << "; should be 1 (true)\n";

		QueueInterface<int>* copyPtr = nullptr;

		if (toupper(userChoice) == 'L')
		{
			copyPtr = new ListQueue<int>(*(ListQueue<int>*)queuePtr);
		}
		else if (toupper(userChoice) == 'A')
		{
			copyPtr = new ArrayQueue<int>(*(ArrayQueue<int>*)queuePtr);
		}
		else
		{
			copyPtr = new LinkedQueue<int>(*(LinkedQueue<int>*)queuePtr);
		}

		std::cout << "copy queuePtr to copyPtr\n";

		std::cout << "Printing queuePtr\n";
		printQueue(queuePtr);
		std::cout << "Printing copyPtr\n";
		printQueue(copyPtr);
		std::cout << "isEmpty(): returns " << queuePtr->isEmpty() << "; should be 0 (false)\n";

		std::cout << "Clearing copyPtr\n";

		while (!copyPtr->isEmpty())
		{
			std::cout << "Dequeueing " << copyPtr->peekFront() << " from copyPtr\n";
			copyPtr->dequeue();
		}
		std::cout << "copyPtr->isEmpty(): returns " << copyPtr->isEmpty() << "; should be 1 (true)\n";
		std::cout << "queuePtr->isEmpty(): returns " << queuePtr->isEmpty() << "; should be 0 (false)\n";

		delete copyPtr;
		copyPtr = nullptr;
	}
public:
	static void TestQueueInterfaceDriver()
	{
		QueueInterface<int>* queuePtr = nullptr;
		char userChoice;
		std::cout << "Enter 'L' to test the list-based implementation\n";
		std::cout << "Enter 'N' to test the linked-based implementation\n";
		std::cout << "Enter 'A' to test the array-based implementation\n";
		std::cin >> userChoice;

		if (toupper(userChoice) == 'L')
		{
			queuePtr = new ListQueue<int>();
			std::cout << "Testing the list-based queue\n\n";
		}
		else if (toupper(userChoice) == 'A')
		{
			queuePtr = new ArrayQueue<int>();
			std::cout << "Testing the array-based queue\n\n";
		}
		else
		{
			queuePtr = new LinkedQueue<int>();
			std::cout << "Testing the linked-based queue\n\n";
		}

		std::cout << "The initial queue is empty\n";
		queueTester(queuePtr, userChoice);
		delete queuePtr;
		queuePtr = nullptr;
		std::cout << "All done!\n";
	}
};