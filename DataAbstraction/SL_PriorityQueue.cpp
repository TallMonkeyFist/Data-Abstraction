#include "SL_PriorityQueue.h"

template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue() : slistPtr(std::make_unique<LinkedSortedList<ItemType>>)
{
}

template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue(const SL_PriorityQueue<ItemType>& aQueue) : slistPtr(std::make_unique<LinkedSortedList<ItemType>>)
{
	for (int i = 0; i < aQueue.slistPtr->getLength(); i++)
	{
		slistPtr->insertSorted(aQueue.slistPtr->getEntry(i));
	}
}


template <class ItemType>
bool SL_PriorityQueue<ItemType>::isEmpty() const
{
	return slistPtr->isEmpty();
}

template <class ItemType>
bool SL_PriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	return slistPtr->insertSorted(newEntry);
}

template <class ItemType>
bool SL_PriorityQueue<ItemType>::dequeue()
{
	return slistPtr->remove(slistPtr->getLength() - 1);
}

template <class ItemType>
ItemType SL_PriorityQueue<ItemType>::peekFront() const throw(PreconViolatedExcept)
{
	if (slistPtr->isEmpty())
	{
		throw PreconViolatedExcept("peekFront() called on an empty queue");
	}
	return slistPtr->getEntry(0);
}