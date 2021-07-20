#pragma once

#include "LinkedBag.h"

template <class ItemType>
void LinkedBag<ItemType>::fillVector(std::vector<ItemType>& bagContents, std::shared_ptr<Node<ItemType>> curPtr) const
{
	if (curPtr != nullptr)
	{
		bagContents.push_back(curPtr->getItem());
		fillVector(bagContents, curPtr->getNext());
	}
}

template <class ItemType>
LinkedBag<ItemType>::LinkedBag() : itemCount(0) , headPtr(nullptr)
{

}

template <class ItemType>
std::shared_ptr<Node<ItemType>> LinkedBag<ItemType>::getPointerTo(const ItemType& target) const
{
	return getPointerTo(target, headPtr);
}

template <class ItemType>
std::shared_ptr<Node<ItemType>> LinkedBag<ItemType>::getPointerTo(const ItemType& target, std::shared_ptr<Node<ItemType>> curPtr) const
{
	if (curPtr == nullptr || curPtr->getItem() == target)
	{
		return curPtr;
	}
	return getPointerTo(target, curPtr->getNext());
}

template <class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
	std::shared_ptr<Node<ItemType>> otherCurrent = aBag.headPtr;

	if (otherCurrent == nullptr)
	{
		headPtr = nullptr;
	}
	else
	{
		headPtr = std::make_shared<Node<ItemType>>();
		headPtr->setItem(otherCurrent->getItem());

		std::shared_ptr<Node<ItemType>> current = headPtr;
		otherCurrent = otherCurrent->getNext();

		while (otherCurrent != nullptr)
		{
			ItemType nextItem = otherCurrent->getItem();
			current->setNext(std::make_shared<Node<ItemType>>(nextItem));

			current = current->getNext();
			otherCurrent = otherCurrent->getNext();
		}

		current->setNext(nullptr);
		current = nullptr;
	}
	otherCurrent = nullptr;
}

template <class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
	std::shared_ptr<Node<ItemType>> newNodePtr = std::make_shared<Node<ItemType>>(newEntry, headPtr);

	headPtr = newNodePtr;
	newNodePtr = nullptr;
	itemCount++;
	return true;
}

template <class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return headPtr == nullptr;
}

template <class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}

template <class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
	std::shared_ptr<Node<ItemType>> current = getPointerTo(anEntry);

	if (current != nullptr)
	{
		current->setItem(headPtr->getItem());

		std::shared_ptr<Node<ItemType>> toDelete = headPtr;
		headPtr = headPtr->getNext();

		toDelete->setNext(nullptr);
		toDelete = nullptr;

		itemCount--;
		return true;
	}

	current = nullptr;
	return false;
}

template <class ItemType>
void LinkedBag<ItemType>::clear()
{
	headPtr = nullptr;
	itemCount = 0;
}

template <class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getPointerTo(anEntry) != nullptr;
}

template <class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int count = 0;
	std::shared_ptr<Node<ItemType>> currentNode = headPtr;

	while (currentNode != nullptr)
	{
		if (currentNode->getItem() == anEntry)
		{
			count++;
		}
		currentNode = currentNode->getNext();
	}

	currentNode = nullptr;
	return count;
}

template <class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
	std::vector<ItemType> contents;
	fillVector(contents, headPtr);
	return contents;
}

template <class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
	clear();
}