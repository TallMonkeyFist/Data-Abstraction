#pragma once

#include "HeapInterface.h"
#include "PreconViolatedExcept.h"
#include <memory>

template <class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType>
{
public:
	ArrayMaxHeap();
	ArrayMaxHeap(const ItemType* someArray, const int arraySize);
	bool isEmpty() const;
	int getNumberOfNodes() const;
	int getHeight() const;
	ItemType peekTop() const throw(PreconViolatedExcept);
	bool add(const ItemType& newData);
	bool remove();
	void clear();
	virtual ~ArrayMaxHeap() { }
private:
	static const int ROOT_INDEX = 0;
	static const int DEFAULT_CAPACITY = 21;
	std::unique_ptr<ItemType[]> items;
	int itemCount;
	int maxItems;

	int getLeftChildIndex(const int nodeIndex) const;
	int getRightChildIndex(const int nodeIndex) const;
	int getParentIndex(const int nodeIndex) const;
	bool isLeaf(int nodeIndex) const;
	void heapRebuild(int nodeIndex);
	void heapRebuildSemi(int nodeIndex);
	void heapCreate();
};

#include "ArrayMaxHeap.cpp"