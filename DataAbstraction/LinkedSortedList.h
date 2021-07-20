#pragma once

#include <memory>
#include "SortedListInterface.h"
#include "Node.h"
#include "PreconViolatedExcept.h"

template <class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType>
{
public:
	LinkedSortedList();
	LinkedSortedList(const LinkedSortedList<ItemType>& aList);
	bool isEmpty() const;
	int getLength() const;
	bool insertSorted(const ItemType& newEntry);
	bool removeSorted(const ItemType& anEntry);
	bool remove(int atIndex) throw(PreconViolatedExcept);
	void clear();
	ItemType getEntry(int atIndex) const;
	int getIndex(const ItemType& anEntry) const;
	virtual ~LinkedSortedList();
private:
	std::shared_ptr<Node<ItemType>> headPtr;
	int itemCount;

	std::shared_ptr<Node<ItemType>> getNodeBefore(const ItemType& anEntry) const;
	std::shared_ptr<Node<ItemType>> getNodeAt(int atIndex) const;
	std::shared_ptr<Node<ItemType>> copyChain(const std::shared_ptr<Node<ItemType>>& origChainPtr);
};

#include "LinkedSortedList.cpp"