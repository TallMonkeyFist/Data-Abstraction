#pragma once

#include "PriorityQueueInterface.h"
#include "PreconViolatedExcept.h"
#include "LinkedSortedList.h"
#include <memory>

template <class ItemType>
class SL_PriorityQueue : public PriorityQueueInterface<ItemType>
{
public:
	SL_PriorityQueue();
	SL_PriorityQueue(const SL_PriorityQueue<ItemType>& aQueue);
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const throw(PreconViolatedExcept);
	~SL_PriorityQueue();
private:
	std::unique_ptr<LinkedSortedList<ItemType>> slistPtr;
};

#include "SL_PriorityQueue.cpp"