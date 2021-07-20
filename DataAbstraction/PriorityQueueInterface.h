#pragma once

template <class ItemType>
class PriorityQueueInterface
{
public:
	virtual bool isEmpty() const = 0;
	virtual bool enqueue(const ItemType& newEntry) = 0;
	virtual bool dequeue() = 0;
	virtual ItemType peekFront() const = 0;
	virtual ~PriorityQueueInterface() { }
};