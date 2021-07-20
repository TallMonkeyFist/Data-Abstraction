#pragma once

template <class ItemType>
class SortedListInterface
{
public:
	virtual bool isEmpty() const = 0;
	virtual int getLength() const = 0;
	virtual bool insertSorted(const ItemType& newEntry) = 0;
	virtual bool removeSorted(const ItemType& anEntry) = 0;
	virtual bool remove(int atIndex) = 0;
	virtual void clear() = 0;
	virtual ItemType getEntry(int atIndex) const = 0;
	virtual int getIndex(const ItemType& anEntry) const = 0;
	virtual ~SortedListInterface() { }
};