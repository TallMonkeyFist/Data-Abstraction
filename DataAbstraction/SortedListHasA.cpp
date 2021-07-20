#include "SortedListHasA.h"
#include "LinkedList.h"

template <class ItemType>
SortedListHasA<ItemType>::SortedListHasA() : listPtr(std::make_unique<LinkedList<ItemType>>())
{
}

template <class ItemType>
SortedListHasA<ItemType>::SortedListHasA(const SortedListHasA<ItemType>& sList) : listPtr(std::make_unique<LinkedList<ItemType>>())
{
	for (int i = 0; i < sList.getLength(); i++)
	{
		listPtr->insert(i, sList.getEntry(i));
	}
}

template <class ItemType>
bool SortedListHasA<ItemType>::isEmpty() const
{
	return listPtr->isEmpty();
}

template <class ItemType>
int SortedListHasA<ItemType>::getLength() const
{
	return listPtr->getLength();
}

template <class ItemType>
bool SortedListHasA<ItemType>::insertSorted(const ItemType& newEntry)
{
	int newIndex = std::abs(getPosition(newEntry)) - 1;
	return listPtr->insert(newIndex, newEntry);
}

template <class ItemType>
bool SortedListHasA<ItemType>::removeSorted(const ItemType& newEntry)
{
	int index = getPosition(newEntry);
	if (index < 1)
	{
		return false;
	}
	return listPtr->remove(index - 1);
}

template <class ItemType>
bool SortedListHasA<ItemType>::remove(int index)
{
	return listPtr->remove(index);
}

template <class ItemType>
void SortedListHasA<ItemType>::clear()
{
	listPtr->clear();
}

template <class ItemType>
ItemType SortedListHasA<ItemType>::getEntry(int atIndex) const throw(PreconViolatedExcept)
{
	if (atIndex < 0 || atIndex >= getLength())
	{
		throw PreconViolatedExcept("getEntry() called with an empty List or invalid position");
	}
	return listPtr->getEntry(atIndex);
}

template <class ItemType>
int SortedListHasA<ItemType>::getIndex(const ItemType& anEntry) const
{
	for (int i = 0; i < listPtr->getLength(); i++)
	{
		if (listPtr->getEntry(i) > anEntry)
		{
			return -1;
		}
		if (listPtr->getEntry(i) == anEntry)
		{
			return i;
		}
	}
	return -1;
}


template <class ItemType>
SortedListHasA<ItemType>::~SortedListHasA()
{
	clear();
	listPtr = nullptr;
}

template <class ItemType>
int SortedListHasA<ItemType>::getPosition(const ItemType& anEntry) const
{
	for (int i = 1; i <= listPtr->getLength(); i++)
	{
		if (listPtr->getEntry(i - 1) > anEntry)
		{
			return -i;
		}
		if (listPtr->getEntry(i - 1) == anEntry)
		{
			return i;
		}
	}
	return ((listPtr->getLength() + 1) * -1);
}