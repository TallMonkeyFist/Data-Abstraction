#include "ArrayList.h"

template <class ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}

template <class ItemType>
bool ArrayList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template <class ItemType>
int ArrayList<ItemType>::getLength() const
{
	return itemCount;
}

template <class ItemType>
bool ArrayList<ItemType>::insert(int atIndex, const ItemType& newEntry)
{
	if (atIndex >= 0 && atIndex <= itemCount && itemCount < maxItems)
	{
		for (int idx = itemCount; idx >= atIndex; idx--)
		{
			items[idx + 1] = items[idx];
		}
		items[atIndex] = newEntry;
		itemCount++;
		return true;
	}
	return false;
}

template <class ItemType>
bool ArrayList<ItemType>::remove(int atIndex)
{
	if (0 <= atIndex && atIndex < itemCount)
	{
		for (int idx = atIndex; idx < itemCount; idx++)
		{
			items[idx] = items[idx + 1];
		}
		itemCount--;
		return true;
	}
	return false;
}

template <class ItemType>
ItemType ArrayList<ItemType>::getEntry(int atIndex) const throw(PreconViolatedExcept)
{
	if (atIndex < 0 || atIndex >= itemCount)
	{
		throw PreconViolatedExcept("getEntry() called with an empty List or invalid position");
	}
	return items[atIndex];
}

template <class ItemType>
void ArrayList<ItemType>::clear()
{
	itemCount = 0;
}

template <class ItemType>
ItemType ArrayList<ItemType>::replace(int atIndex, const ItemType& newEntry) throw(PreconViolatedExcept)
{
	if (atIndex < 0 || atIndex >= itemCount)
	{
		throw PreconViolatedExcept("replace() called with an empty List or invalid position");
	}
	ItemType oldEntry = items[atIndex];
	items[atIndex] = newEntry;
	return oldEntry;
}