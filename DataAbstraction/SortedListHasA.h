#pragma once

#include "Node.h"
#include "ListInterface.h"
#include "SortedListInterface.h"
#include "PreconViolatedExcept.h"
#include <memory>

template <class ItemType>
class SortedListHasA : public SortedListInterface<ItemType>
{
public:
	SortedListHasA();
	SortedListHasA(const SortedListHasA& sList);
	bool isEmpty() const;
	int getLength() const;
	bool insertSorted(const ItemType& newEntry);
	bool removeSorted(const ItemType& anEntry);
	bool remove(int atIndex);
	void clear();
	ItemType getEntry(int atIndex) const throw(PreconViolatedExcept);
	int getIndex(const ItemType& anEntry) const;
	virtual ~SortedListHasA();
private:
	std::unique_ptr<ListInterface<ItemType>> listPtr;
	int getPosition(const ItemType& anEntry) const;
};

#include "SortedListHasA.cpp"