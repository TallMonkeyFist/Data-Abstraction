#include <cassert>
#include "LinkedSortedList.h"

template <class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : itemCount(0), headPtr(nullptr)
{

}

template <class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList)
{
	headPtr = copyChain(aList.headPtr);
	itemCount = aList.itemCount;
}

template <class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
	return headPtr == nullptr;
}

template <class ItemType>
int LinkedSortedList<ItemType>::getLength() const
{
	return itemCount;
}

template <class ItemType>
bool LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
	std::shared_ptr<Node<ItemType>> newNodePtr = std::make_shared<Node<ItemType>>(newEntry);
	std::shared_ptr<Node<ItemType>> prevPtr = getNodeBefore(newEntry);

	if (isEmpty() || prevPtr == nullptr)
	{
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
	}
	else
	{
		std::shared_ptr<Node<ItemType>> aftPtr = prevPtr->getNext();
		prevPtr->setNext(newNodePtr);
		newNodePtr->setNext(aftPtr);
	}
	itemCount++;
	return true;
}

template <class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry)
{
	std::shared_ptr<Node<ItemType>> prevPtr = getNodeBefore(anEntry);

	if (prevPtr != nullptr)
	{
		if (prevPtr->getNext() != nullptr)
		{
			prevPtr->setNext(prevPtr->getNext()->getNext());
		}
		else
		{
			prevPtr->setNext(nullptr);
		}
		itemCount--;
		return true;
	}
	return false;
}

template <class ItemType>
bool LinkedSortedList<ItemType>::remove(int atIndex) throw(PreconViolatedExcept)
{
	if (atIndex < 0 || atIndex >= itemCount)
	{
		throw PreconViolatedExcept("remove() called with an empty List or invalid position");
	}
	std::shared_ptr<Node<ItemType>> toRemove = nullptr;
	if (atIndex == 0)
	{
		toRemove = headPtr;
		headPtr = headPtr->getNext();
		toRemove->setNext(nullptr);
	}
	else
	{
		std::shared_ptr<Node<ItemType>> prevPtr = getNodeAt(atIndex - 1);
		toRemove = prevPtr->getNext();

		prevPtr->setNext(toRemove->getNext());
		toRemove->setNext(nullptr);
	}
	itemCount--;
	return true;
}

template <class ItemType>
void LinkedSortedList<ItemType>::clear()
{
	headPtr = nullptr;
	itemCount = 0;
}

template <class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int atIndex) const
{
	if (atIndex < 0 || atIndex >= itemCount)
	{
		throw PreconViolatedExcept("getEntry() called with an empty List or invalid position");
	}
	return getNodeAt(atIndex)->getItem();
}

template <class ItemType>
int LinkedSortedList<ItemType>::getIndex(const ItemType& anEntry) const
{
	std::shared_ptr<Node<ItemType>> curPtr = headPtr;
	int curIndex = 0;

	while (curPtr != nullptr && curPtr->getItem() != anEntry)
	{
		curIndex++;
		curPtr = curPtr->getNext();
	}
	if (curPtr == nullptr)
	{
		return -1;
	}
	return curIndex;
}

template <class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{
	clear();
}

template <class ItemType>
std::shared_ptr<Node<ItemType>> LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
	std::shared_ptr<Node<ItemType>> prevPtr = nullptr;
	std::shared_ptr<Node<ItemType>> curPtr = headPtr;

	while (curPtr != nullptr && anEntry > curPtr->getItem())
	{
		prevPtr = curPtr;
		curPtr = curPtr->getNext();
	}

	return prevPtr;
}

template <class ItemType>
std::shared_ptr<Node<ItemType>> LinkedSortedList<ItemType>::getNodeAt(int atIndex) const
{
	assert(0 <= atIndex && atIndex < itemCount);

	int curIndex = 0;
	std::shared_ptr<Node<ItemType>> curPtr = headPtr;

	while (curIndex < atIndex)
	{
		curPtr = curPtr->getNext();
		curIndex++;
	}

	return curPtr;
}

template <class ItemType>
std::shared_ptr<Node<ItemType>> LinkedSortedList<ItemType>::copyChain(const std::shared_ptr<Node<ItemType>>& origChainPtr)
{
	std::shared_ptr<Node<ItemType>> copiedChainPtr;
	if (origChainPtr != nullptr)
	{
		copiedChainPtr = std::make_shared<Node<ItemType>>(origChainPtr->getItem());
		copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
	}
	return copiedChainPtr;
}