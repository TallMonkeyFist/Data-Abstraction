#include "ArrayQueue.h"

template <class ItemType>
ArrayQueue<ItemType>::ArrayQueue()
{
	front = 0;
	back = 0;
	count = 0;
	items[DEFAULT_CAPACITY];
}

template <class ItemType>
ArrayQueue<ItemType>::ArrayQueue(const ArrayQueue& aQueue)
{
	for (int i = 0; i < DEFAULT_CAPACITY; i++)
	{
		items[i] = aQueue.items[i];
	}
	count = aQueue.count;
	front = aQueue.front;
	back = aQueue.back;
}

template <class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const
{
	return count == 0;
}

template <class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	if (count < DEFAULT_CAPACITY)
	{
		back = (back + 1) % DEFAULT_CAPACITY;
		items[back] = newEntry;
		count++;
		return true;
	}
	return false;
}

template <class ItemType>
bool ArrayQueue<ItemType>::dequeue()
{
	if (count > 0)
	{
		front = (front + 1) % DEFAULT_CAPACITY;
		count--;
		return true;
	}
	return false;
}

template <class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const throw(PreconViolatedExcept)
{
	if (count <= 0)
	{
		throw PreconViolatedExcept("peekFront() called on an empty queue");
	}
	return items[front];
}