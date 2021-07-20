#include "SortedListIsA.h"

template <class ItemType>
SortedListIsA<ItemType>::SortedListIsA()
{
}

template <class ItemType>
SortedListIsA<ItemType>::SortedListIsA(const SortedListIsA<ItemType>& sList) : LinkedList<ItemType>(sList)
{
}

template <class ItemType>
bool SortedListIsA<ItemType>::insertSorted(const ItemType& newEntry)
{
	int index = std::abs(getPosition(newEntry)) - 1;
	return LinkedList<ItemType>::insert(index, newEntry);
}

template <class ItemType>
bool SortedListIsA<ItemType>::removeSorted(const ItemType& newEntry)
{
	int index = getPosition(newEntry);
	if (index < 1)
	{
		return false;
	}
	return LinkedList<ItemType>::remove(index - 1);
}

template <class ItemType>
int SortedListIsA<ItemType>::getIndex(const ItemType& anEntry) const
{
	for (int i = 0; i < LinkedList<ItemType>::getLength(); i++)
	{
		if (LinkedList<ItemType>::getEntry(i) > anEntry)
		{
			return -1;
		}
		if (LinkedList<ItemType>::getEntry(i) == anEntry)
		{
			return i;
		}
	}
	return -1;
}

template <class ItemType>
bool SortedListIsA<ItemType>::insert(int atIndex, const ItemType& newEntry)
{
	return false;
}

template <class ItemType>
ItemType SortedListIsA<ItemType>::replace(int atIndex, const ItemType& newEntry) throw(PreconViolatedExcept)
{
	return false;
}

template <class ItemType>
int SortedListIsA<ItemType>::getPosition(const ItemType& anEntry) const
{
	for (int i = 1; i <= LinkedList<ItemType>::getLength(); i++)
	{
		if (LinkedList<ItemType>::getEntry(i - 1) > anEntry)
		{
			return -i;
		}
		if (LinkedList<ItemType>::getEntry(i - 1) == anEntry)
		{
			return i;
		}
	}
	return (LinkedList<ItemType>::getLength() + 1) * -1;
}

template <class ItemType>
SortedListIsA<ItemType>::~SortedListIsA()
{
}