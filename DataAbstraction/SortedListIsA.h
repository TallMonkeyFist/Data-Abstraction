#pragma once

#include <memory>
#include "PreconViolatedExcept.h"
#include "Node.h"
#include "LinkedList.h"

template <class ItemType>
class SortedListIsA : public LinkedList<ItemType>
{
private:
	int getPosition(const ItemType& anEntry) const;

public:
	SortedListIsA();
	SortedListIsA(const SortedListIsA& sList);
	
	bool insertSorted(const ItemType& newEntry);
	bool removeSorted(const ItemType& anEntry);
	int getIndex(const ItemType& anEntry) const;

	bool insert(int newIndex, const ItemType& newEntry) override;
	ItemType replace(int index, const ItemType& newEntry) throw(PreconViolatedExcept)override;

	virtual ~SortedListIsA();
};

#include "SortedListIsA.cpp"