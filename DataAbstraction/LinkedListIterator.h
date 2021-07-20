#pragma once

#include <iterator>
#include "Node.h"

template <class ItemType>
class LinkedList;

template <class ItemType>
class LinkedListIterator : public std::iterator<std::input_iterator_tag, int>
{
public:
	LinkedListIterator(const std::shared_ptr<LinkedList<ItemType>> someList, std::shared_ptr<Node<ItemType>> nodePtr = nullptr);
	const ItemType operator*();
	LinkedListIterator<ItemType> operator++();
	bool operator==(const LinkedListIterator<ItemType>& rightHandSide) const;
	bool operator!=(const LinkedListIterator<ItemType>& rightHandSide) const;
	~LinkedListIterator();
private:
	const std::shared_ptr<LinkedList<ItemType>> containerPtr;
	std::shared_ptr<Node<ItemType>> currentItemPtr;
};

#include "LinkedListIterator.cpp"