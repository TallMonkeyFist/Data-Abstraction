#pragma once

#include "QueueInterface.h"
#include "PreconViolatedExcept.h"

template <class ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
public:
	ArrayQueue();
	ArrayQueue(const ArrayQueue& aQueue);
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const throw(PreconViolatedExcept);
	~ArrayQueue() { }
private:
	static const int DEFAULT_CAPACITY = 50;
	ItemType items[DEFAULT_CAPACITY];
	int front;
	int back;
	int count;
};

#include "ArrayQueue.cpp"