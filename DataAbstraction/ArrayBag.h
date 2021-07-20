#pragma once

#include "BagInterface.h"
#include <ostream>

template <class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 6;
	ItemType* items;
	int itemCount;
	int maxItems;

	int getIndexOf(const ItemType& target) const;
	friend std::ostream& operator<<(std::ostream& o, const ArrayBag<ItemType>& bag)
	{
		for (int i = 0; i < bag.itemCount; i++)
		{
			o << bag.items[i] << std::endl;
		}

		return o;
	}

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	std::vector<ItemType> toVector() const;
	virtual ~ArrayBag();
};

#include "ArrayBag.cpp"