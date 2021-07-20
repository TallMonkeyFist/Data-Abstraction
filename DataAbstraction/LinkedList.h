#pragma once

#include "ListInterface.h"
#include "LinkedListIterator.h"
#include "PreconViolatedExcept.h"
#include "Node.h"

template <class ItemType>
class LinkedList : public ListInterface<ItemType>
{
public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();

	bool isEmpty() const;
	int getLength() const;
	bool insert(int atIndex, const ItemType& newEntry);
	bool remove(int atIndex);
	void clear();
	/**@throw PreconViolatedExcept if atIndex < 0 or atIndex >= getLength()*/
	ItemType getEntry(int atIndex) const throw(PreconViolatedExcept);
	/**@throw PreconViolatedExcept if atIndex < 0 or atIndex >= getLength()*/
	ItemType replace(int atIndex, const ItemType&) throw(PreconViolatedExcept);

	bool operator==(const LinkedList<ItemType>& rightHandSide) const;

	LinkedListIterator<ItemType> begin() const;
	LinkedListIterator<ItemType> end() const;

private:
	std::shared_ptr<Node<ItemType>> headPtr;
	int itemCount;
	/**Locates a specified node in a linked list.
	@pre atIndex is the index of the desired node;
		at 0 <= atIndex and atIndex < itemCount
	@post	The node is found and a pointer to it is returned.
	@param atIndex	The index of the node to locate
	@return A pointer to the node at the given position*/
	std::shared_ptr<Node<ItemType>> getNodeAt(int atIndex) const;
	std::shared_ptr<Node<ItemType>> insertNode(int atIndex, std::shared_ptr<Node<ItemType>> newNodePtr, std::shared_ptr<Node<ItemType>> subChainPtr);
};

#include "LinkedList.cpp";