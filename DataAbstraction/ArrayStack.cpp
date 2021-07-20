#include <cassert>
#include "ArrayStack.h"

template <class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{

}

template <class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
	return top < 0;
}

template <class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
	if (top < DEFAULT_CAPACITY - 1)
	{
		top++;
		items[top] = newEntry;
		return true;
	}
	return false;
}

template <class ItemType>
bool ArrayStack<ItemType>::pop()
{
	if (top >= 0)
	{
		top--;
		return true;
	}
	return false;
}

template <class ItemType>
ItemType ArrayStack<ItemType>::peek() const throw(PreconViolatedExcept)
{
	if (isEmpty())
	{
		throw PreconViolatedExcept("peek() called with empty stack");
	}

	return items[top];
}