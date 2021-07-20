#pragma once


#include "StackInterface.h"
#include "PreconViolatedExcept.h"

template <class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
public:
	ArrayStack();
	bool isEmpty() const;
	bool push(const ItemType& newEntry);
	bool pop();
	ItemType peek() const throw(PreconViolatedExcept);
private:
	static const int DEFAULT_CAPACITY = 25;
	ItemType items[DEFAULT_CAPACITY];
	int top;
};

#include "ArrayStack.cpp"