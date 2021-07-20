#pragma once

#include "QueueInterface.h"
#include "PreconViolatedExcept.h"
#include "LinkedList.h"
#include <memory>

template <class ItemType>
class ListQueue : public QueueInterface<ItemType>
{
public:
	ListQueue();
	ListQueue(const ListQueue<ItemType>& aQueue);
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const throw(PreconViolatedExcept);
	~ListQueue();
private:
	std::unique_ptr<LinkedList<ItemType>> listPtr;
};

#include "ListQueue.cpp"