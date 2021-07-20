#pragma once

#include "PriorityQueueInterface.h"
#include "ArrayMaxHeap.h"

template <class ItemType>
class HeapPriorityQueue : public PriorityQueueInterface<ItemType>, private ArrayMaxHeap<ItemType>
{
public:
	HeapPriorityQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const throw(PreconViolatedExcept);
};