#include "LinkedList.h"
#include <memory>
#include <cassert>

template <class ItemType>
LinkedList<ItemType>::LinkedList() : itemCount(0), headPtr(nullptr)
{
}

template <class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
	for (int i = 0; i < aList.getLength(); i++)
	{
		insert(i, aList.getEntry(i));
	}
}

template <class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
}

template <class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template <class ItemType>
int LinkedList<ItemType>::getLength() const
{
	return itemCount;
}

template <class ItemType>
std::shared_ptr<Node<ItemType>> LinkedList<ItemType>::getNodeAt(int atIndex) const
{
	assert(atIndex >= 0 && atIndex < itemCount);
	std::shared_ptr<Node<ItemType>> curPtr = headPtr;
	for (int i = 0; i < atIndex; i++)
	{
		curPtr = curPtr->getNext();
	}

	return curPtr;
}

template <class ItemType>
std::shared_ptr<Node<ItemType>> LinkedList<ItemType>::insertNode(int atIndex, std::shared_ptr<Node<ItemType>> newNodePtr, std::shared_ptr<Node<ItemType>> subChainPtr)
{
	if (atIndex == 0)
	{
		newNodePtr->setNext(subChainPtr);
		subChainPtr = newNodePtr;
		itemCount++;
	}
	else
	{
		std::shared_ptr<Node<ItemType>> afterPtr = insertNode(atIndex - 1, newNodePtr, subChainPtr->getNext());
		subChainPtr->setNext(afterPtr);
		afterPtr = nullptr;
	}
	return subChainPtr;
}

template <class ItemType>
bool LinkedList<ItemType>::insert(int atIndex, const ItemType& newEntry)
{
	if (atIndex >= 0 && atIndex <= itemCount)
	{
		std::shared_ptr<Node<ItemType>> newNodePtr = std::make_shared<Node<ItemType>>(newEntry);
		headPtr = insertNode(atIndex, newNodePtr, headPtr);
		return true;
	}
	return false;
}

template <class ItemType>
bool LinkedList<ItemType>::remove(int atIndex)
{
	if (atIndex < 0 || atIndex >= itemCount)
	{
		return false;
	}
	std::shared_ptr<Node<ItemType>> nodeToDelete = nullptr;
	if (atIndex == 0)
	{
		nodeToDelete = headPtr;
		headPtr = nodeToDelete->getNext();
	}
	else
	{
		std::shared_ptr<Node<ItemType>> prevNode = getNodeAt(atIndex - 1);
		nodeToDelete = prevNode->getNext();
		prevNode->setNext(nodeToDelete->getNext());
		prevNode = nullptr;
	}
	nodeToDelete = nullptr;
	itemCount--;

	return true;
}

template <class ItemType>
void LinkedList<ItemType>::clear()
{
	headPtr = nullptr;
	itemCount = 0;
}

template <class ItemType>
ItemType LinkedList<ItemType>::getEntry(int atIndex) const throw(PreconViolatedExcept)
{
	if (atIndex < 0 || atIndex >= itemCount)
	{
		throw PreconViolatedExcept("getEntry() called with an empty List or invalid position");
	}
	return getNodeAt(atIndex)->getItem();
}

template <class ItemType>
ItemType LinkedList<ItemType>::replace(int atIndex, const ItemType& newEntry) throw(PreconViolatedExcept)
{
	if (atIndex < 0 || atIndex >= itemCount)
	{
		throw PreconViolatedExcept("replace() called with an empty List or invalid position");
	}
	std::shared_ptr<Node<ItemType>> nodeToReplace = getNodeAt(atIndex);
	ItemType oldEntry = nodeToReplace->getItem();
	nodeToReplace->setItem(newEntry);
	return oldEntry;
}

template <class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList<ItemType>& rightHandSide) const
{
	return std::addressof(*this) == std::addressof(rightHandSide);
}

template <class ItemType>
LinkedListIterator<ItemType> LinkedList<ItemType>::begin() const
{
	LinkedListIterator<ItemType> iter(std::make_shared<LinkedList<ItemType>>(*this), headPtr);
	return iter;
}

template <class ItemType>
LinkedListIterator<ItemType> LinkedList<ItemType>::end() const
{
	LinkedListIterator<ItemType> iter(std::make_shared<LinkedList<ItemType>>(*this), nullptr);
	return iter;
}