#include"ArrayBag.h"

template <class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
	items = new ItemType[DEFAULT_CAPACITY];
}

template <class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}

template <class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template <class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoom = itemCount < maxItems;

	if (!hasRoom)
	{
		ItemType* oldArray = items;
		items = new ItemType[maxItems * 2];
		for (int i = 0; i < maxItems; i++)
		{
			items[i] = oldArray[i];
		}
		delete[] oldArray;
		maxItems *= 2;
	}

	items[itemCount++] = newEntry;

	return true;
}

template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);

	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}

	return canRemoveItem;
}

template <class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}

template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const
{
	return getIndexOf(target) == -1 ? false : true;
}

template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int count = 0;
	for (int i = 0; i < itemCount; i++)
	{
		if (items[i] == anEntry)
		{
			count++;
		}
	}
	return count;
}

template <class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
	{
		bagContents.push_back(items[i]);
	}
	return bagContents;
}

template <class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& anEntry) const
{
	for (int i = 0; i < itemCount; i++)
	{
		if (items[i] == anEntry)
		{
			return i;
		}
	}
	return -1;
}

template <class ItemType>
ArrayBag<ItemType>::~ArrayBag()
{
	delete[] items;
	items = nullptr;
}