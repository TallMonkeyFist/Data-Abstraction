#include "ArrayMaxHeap.h"
#include <cmath>

template <class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap()
{
	itemCount = 0;
	maxItems = DEFAULT_CAPACITY;
	items = std::make_unique<ItemType[]>(DEFAULT_CAPACITY);

}

template <class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType* someArray, const int arraySize) : itemCount(arraySize), maxItems(2 * arraySize)
{
	items = std::make_unique<ItemType[]>(maxItems);
	for (int i = 0; i < arraySize; i++)
	{
		items[i] = someArray[i];
	}
	heapCreate();
}

template <class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template <class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
	return itemCount;
}

template <class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
	if (isEmpty())
		return 0;
	return (int) (std::log2(itemCount) + 1);
}

template <class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const throw(PreconViolatedExcept)
{
	if (isEmpty())
	{
		throw PreconViolatedExcept("peekTop() called on an empty heap\n");
	}
	return items[0];
}

template <class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newEntry)
{
	if (itemCount == maxItems)
	{
		return false;
	}
	items[itemCount] = newEntry;
	itemCount++;
	int parentIndex = getParentIndex(itemCount - 1);
	while (parentIndex >= 0)
	{
		heapRebuild(parentIndex);
		parentIndex = getParentIndex(parentIndex);
	}
	return true;
}

template <class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
	if (isEmpty())
	{
		return false;
	}
	items[0] = items[itemCount - 1];
	itemCount--;
	heapRebuildSemi(0);
	return true;
}

template <class ItemType>
void ArrayMaxHeap<ItemType>::clear()
{
	itemCount = 0;
}

template <class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
	int leftChildIndex = (nodeIndex * 2) + 1;
	return leftChildIndex;
}

template <class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
	int rightChildIndex = (nodeIndex * 2) + 2;
	return rightChildIndex;
}

template <class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(const int nodeIndex) const
{
	if (nodeIndex < 0 || nodeIndex >= itemCount)
	{
		return -1;
	}
	if (nodeIndex % 2 == 0)
	{
		return (nodeIndex - 2) / 2;
	}

	return (nodeIndex - 1) / 2;
}

template <class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(const int nodeIndex) const
{
	if (getLeftChildIndex(nodeIndex) >= itemCount && getRightChildIndex(nodeIndex) >= itemCount)
	{
		return true;
	}
	return false;
}

template <class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int nodeIndex)
{
	if (isLeaf(nodeIndex))
		return;

	int leftChild = getLeftChildIndex(nodeIndex);
	int rightChild = getRightChildIndex(nodeIndex);
	int swapIndex = rightChild;
	if (swapIndex >= itemCount || items[leftChild] > items[rightChild])
	{
		swapIndex = leftChild;
	}
	if (items[nodeIndex] < items[swapIndex])
	{
		std::swap(items[nodeIndex], items[swapIndex]);
	}
}

template <class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuildSemi(int nodeIndex)
{
	if(isLeaf(nodeIndex))
		return;

	int leftChildIndex = getLeftChildIndex(nodeIndex);
	int rightChildIndex = getRightChildIndex(nodeIndex);
	int largerChildIndex = rightChildIndex;
	if (largerChildIndex >= itemCount || items[leftChildIndex] > items[rightChildIndex])
	{
		largerChildIndex = leftChildIndex;
	}
	if (items[nodeIndex] < items[largerChildIndex])
	{
		std::swap(items[nodeIndex], items[largerChildIndex]);
		heapRebuild(largerChildIndex);
	}
}

template <class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
	for (int i = itemCount / 2 - 1; i >= 0; i++)
	{
		heapRebuild(i);
	}
}