#pragma once
#include "StackInterface.h"
#include "Node.h"
#include "PreconViolatedExcept.h"

template <class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
public:
	LinkedStack();
	LinkedStack(const LinkedStack<ItemType>& aStack);
	virtual ~LinkedStack();

	bool isEmpty() const;
	bool push(const ItemType& newEntry);
	bool pop();
	ItemType peek() const throw(PreconViolatedExcept);
private:
	std::shared_ptr<Node<ItemType>> topPtr;
};

#include "LinkedStack.cpp"