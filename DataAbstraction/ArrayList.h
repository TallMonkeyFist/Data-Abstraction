#pragma once

#include "ListInterface.h"
#include "PreconViolatedExcept.h"

template <class ItemType>
class ArrayList : public ListInterface<ItemType>
{
public:
	ArrayList();

	bool isEmpty() const;
	int getLength() const;
	bool insert(int atIndex, const ItemType& newEntry);
	bool remove(int atIndex);
	void clear();
	/**@throw PreconViolatedExcept if atIndex < 0 or atIndex >= getLength()*/
	ItemType getEntry(int atIndex) const throw(PreconViolatedExcept);
	/**@throw PreconViolatedExcept if atIndex < 0 or atIndex >= getLength()*/
	ItemType replace(int atIndex, const ItemType&) throw(PreconViolatedExcept);

private:
	static const int DEFAULT_CAPACITY = 100;
	ItemType items[DEFAULT_CAPACITY];
	int itemCount;
	int maxItems;
};

#include "ArrayList.cpp"