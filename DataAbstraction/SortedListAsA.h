#pragma once
#include "Node.h"
#include "SortedListInterface.h"
#include "LinkedList.h"
#include "PreconViolatedExcept.h"

template <class ItemType>
class SortedListAsA : public SortedListInterface<ItemType>, private LinkedList<ItemType>
{
public:
	SortedListAsA();
	SortedListAsA(const SortedListAsA<ItemType>& sList);
	bool isEmpty() const;
	int getLength() const;
	bool insertSorted(const ItemType& newEntry);
	bool removeSorted(const ItemType& anEntry);
	bool remove(int atIndex);
	void clear();
	ItemType getEntry(int atIndex) const throw(PreconViolatedExcept);
	int getIndex(const ItemType& anEntry) const;
	~SortedListAsA();
private:
	int getPosition(const ItemType& anEntry) const;
};

#include "SortedListAsA.cpp"