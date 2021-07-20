#pragma once

template <class ItemType>
class HeapInterface
{
public:
	virtual bool isEmpty() const = 0;
	virtual int getNumberOfNodes() const = 0;
	virtual int getHeight() const = 0;
	virtual ItemType peekTop() const = 0;
	virtual bool add(const ItemType& newData) = 0;
	virtual bool remove() = 0;
	virtual void clear() = 0;
	virtual ~HeapInterface() { }
};