#include "LinkedQueue.h"

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{
}

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue<ItemType>& aQueue)
{
	if (aQueue.isEmpty())
	{
		frontPtr = nullptr;
		backPtr = nullptr;
		return;
	}

	std::shared_ptr<Node<ItemType>> curPtr = aQueue.frontPtr;
	frontPtr = std::make_shared<Node<ItemType>>(curPtr->getItem());
	backPtr = frontPtr;
	curPtr = curPtr->getNext();
	std::shared_ptr<Node<ItemType>> newNodeEntry = nullptr;
	while (curPtr != nullptr)
	{
		newNodeEntry = std::make_shared<Node<ItemType>>(curPtr->getItem(), nullptr);
		backPtr->setNext(newNodeEntry);
		backPtr = newNodeEntry;
		curPtr = curPtr->getNext();
	}
}

template <class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
	return frontPtr == nullptr;
}

template <class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	std::shared_ptr<Node<ItemType>> newNodeEntry = std::make_shared<Node<ItemType>>(newEntry, nullptr);
	if (backPtr == nullptr)
	{
		frontPtr = newNodeEntry;
	}
	else
	{
		backPtr->setNext(newNodeEntry);
	}
	backPtr = newNodeEntry;
	return true;
}

template <class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	if (frontPtr == nullptr)
	{
		return false;
	}
	if (backPtr == frontPtr)
	{
		backPtr.reset();
		frontPtr.reset();
		return true;
	}
	std::shared_ptr<Node<ItemType>> nodeToDelete = frontPtr;
	frontPtr = frontPtr->getNext();
	nodeToDelete->setNext(nullptr);
	return true;
}

template <class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const throw(PreconViolatedExcept)
{
	if (frontPtr == nullptr)
	{
		throw PreconViolatedExcept("peekFront() called on an empty queue");
	}
	return frontPtr->getItem();
}

template <class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
	frontPtr.reset();
	backPtr.reset();
}