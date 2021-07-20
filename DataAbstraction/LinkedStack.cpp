#include <cassert>
#include "LinkedStack.h"

template <class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr)
{
}

template <class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
	std::shared_ptr<Node<ItemType>> nodeToCopy = aStack.topPtr;
	if (nodeToCopy == nullptr)
	{
		topPtr = nullptr;
		return;
	}

	topPtr = std::make_shared<Node<ItemType>>(nodeToCopy->getItem(), nullptr);

	nodeToCopy = nodeToCopy->getNext();
	std::shared_ptr<Node<ItemType>> currentNode = topPtr;
	std::shared_ptr<Node<ItemType>> nodeToAdd = nullptr;

	while (nodeToCopy != nullptr)
	{
		nodeToAdd = std::make_shared<Node<ItemType>>(nodeToCopy->getItem(), nullptr);
		currentNode->setNext(nodeToAdd);

		currentNode = currentNode->getNext();
		nodeToCopy = nodeToCopy->getNext();

	}

	currentNode = nullptr;
	nodeToAdd = nullptr;
}

template <class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	return topPtr == nullptr;
}

template <class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry)
{
	std::shared_ptr<Node<ItemType>> newNode = std::make_shared<Node<ItemType>>(newEntry, topPtr);
	topPtr = newNode;
	newNode = nullptr;
	return true;
}

template <class ItemType>
bool LinkedStack<ItemType>::pop()
{
	if (!isEmpty())
	{
		std::shared_ptr<Node<ItemType>> nodeToDelete = topPtr;
		topPtr = topPtr->getNext();
		nodeToDelete->setNext(nullptr);
		nodeToDelete = nullptr;
		return true;
	}
	return false;
}

template <class ItemType>
ItemType LinkedStack<ItemType>::peek() const throw(PreconViolatedExcept)
{
	if (isEmpty())
	{
		throw PreconViolatedExcept("peek() called with empty stack");
	}

	return topPtr->getItem();
}

template <class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	topPtr = nullptr;
}