#include "ListQueue.h"

template <class ItemType>
ListQueue<ItemType>::ListQueue() : listPtr(std::make_unique<LinkedList<ItemType>>())
{
}

template <class ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue<ItemType>& aQueue)
{
	listPtr = std::make_unique<LinkedList<ItemType>>();
	for (int i = 0; i < aQueue.listPtr->getLength(); i++)
	{
		listPtr->insert(i, aQueue.listPtr->getEntry(i));
	}
}

template <class ItemType>
bool ListQueue<ItemType>::isEmpty() const
{
	return listPtr->isEmpty();
}

template <class ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	return listPtr->insert(listPtr->getLength() , newEntry);
}

template <class ItemType>
bool ListQueue<ItemType>::dequeue()
{
	return listPtr->remove(0);
}

template <class ItemType>
ItemType ListQueue<ItemType>::peekFront() const throw(PreconViolatedExcept)
{
	if (listPtr->isEmpty())
	{
		throw PreconViolatedExcept("peekFront() called on an empty queue");
	}
	return listPtr->getEntry(0);
}

template <class ItemType>
ListQueue<ItemType>::~ListQueue()
{
}