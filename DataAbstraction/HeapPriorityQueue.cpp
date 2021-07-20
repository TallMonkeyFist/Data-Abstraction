#include "HeapPriorityQueue.h"

template <class ItemType>
HeapPriorityQueue<ItemType>::HeapPriorityQueue()
{
	ArrayMaxHeap<ItemType>();
}

template <class ItemType>
bool HeapPriorityQueue<ItemType>::isEmpty() const
{
	return ArrayMaxHeap<ItemType>::isEmpty();
}

template <class ItemType>
bool HeapPriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	return ArrayMaxHeap<ItemType>::add(newEntry);
}

template <class ItemType>
bool HeapPriorityQueue<ItemType>::dequeue()
{
	return ArrayMaxHeap<ItemType>::remove();
}

template <class ItemType>
ItemType HeapPriorityQueue<ItemType>::peekFront() const throw(PreconViolatedExcept)
{
	if (isEmpty())
	{
		throw PreconViolatedExcept("peekFront() called on an empty queue\n");
	}
	return ArrayMaxHeap<ItemType>::peekTop();
}