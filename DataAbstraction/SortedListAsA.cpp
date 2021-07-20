#include "SortedListAsA.h"

template <class ItemType>
SortedListAsA<ItemType>::SortedListAsA()
{
}

template <class ItemType>
SortedListAsA<ItemType>::SortedListAsA(const SortedListAsA<ItemType>& sList) : LinkedList<ItemType>(sList)
{
}

template <class ItemType>
bool SortedListAsA<ItemType>::isEmpty() const
{
	return LinkedList<ItemType>::isEmpty();
}

template <class ItemType>
int SortedListAsA<ItemType>::getLength() const
{
	return LinkedList<ItemType>::getLength();
}

template <class ItemType>
bool SortedListAsA<ItemType>::insertSorted(const ItemType& newEntry)
{
	int newIndex = std::abs(getPosition(newEntry)) - 1;
	return LinkedList<ItemType>::insert(newIndex, newEntry);
}

template <class ItemType>
bool SortedListAsA<ItemType>::removeSorted(const ItemType& newEntry)
{
	int index = getPosition(newEntry);
	if (index < 1)
	{
		return false;
	}
	return LinkedList<ItemType>::remove(index - 1);
}

template <class ItemType>
bool SortedListAsA<ItemType>::remove(int index)
{
	return LinkedList<ItemType>::remove(index);
}

template <class ItemType>
void SortedListAsA<ItemType>::clear()
{
	LinkedList<ItemType>::clear();
}

template <class ItemType>
ItemType SortedListAsA<ItemType>::getEntry(int atIndex) const throw(PreconViolatedExcept)
{
	return LinkedList<ItemType>::getEntry(atIndex);
}

template <class ItemType>
int SortedListAsA<ItemType>::getIndex(const ItemType& anEntry) const
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
int SortedListAsA<ItemType>::getPosition(const ItemType& anEntry) const
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
	return ((LinkedList<ItemType>::getLength() + 1) * -1);
}

template <class ItemType>
SortedListAsA<ItemType>::~SortedListAsA()
{
}