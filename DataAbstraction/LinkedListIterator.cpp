#include "LinkedListIterator.h"
#include <iostream>
template <class ItemType>
LinkedListIterator<ItemType>::LinkedListIterator(
	std::shared_ptr<LinkedList<ItemType>> someList, 
	std::shared_ptr<Node<ItemType>> nodePtr) 
		: containerPtr(someList), currentItemPtr(nodePtr)
{
}

template <class ItemType>
const ItemType LinkedListIterator<ItemType>::operator*()
{
	return currentItemPtr->getItem();
}

template <class ItemType>
LinkedListIterator<ItemType> LinkedListIterator<ItemType>::operator++()
{
	std::cout << "\niterting forward\n";
	currentItemPtr = currentItemPtr->getNext();
	return *this;
}

template <class ItemType>
bool LinkedListIterator<ItemType>::operator==(const LinkedListIterator<ItemType>& rightHandSide) const
{
	return ((containerPtr == rightHandSide.containerPtr) && (currentItemPtr == rightHandSide.currentItemPtr));
}

template <class ItemType>
bool LinkedListIterator<ItemType>::operator!=(const LinkedListIterator<ItemType>& rightHandSide) const
{
	bool sameContainer = (containerPtr && rightHandSide.containerPtr) ? (*containerPtr.get() == *(rightHandSide.containerPtr).get()) : (!containerPtr && !rightHandSide.containerPtr);
	return ((sameContainer) || (currentItemPtr != rightHandSide.currentItemPtr));
}

template <class ItemType>
LinkedListIterator<ItemType>::~LinkedListIterator()
{

}