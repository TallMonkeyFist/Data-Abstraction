#pragma once

#include "QueueInterface.h"
#include "Node.h"
#include "PreconViolatedExcept.h"
#include <memory>

template <class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue<ItemType>& aQueue);
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const throw(PreconViolatedExcept);
	~LinkedQueue();
private:
	std::shared_ptr<Node<ItemType>> frontPtr;
	std::shared_ptr<Node<ItemType>> backPtr;
};

#include "LinkedQueue.cpp"