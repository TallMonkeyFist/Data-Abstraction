#pragma once


#include "BagInterface.h"
#include "Node.h"

template <class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
	std::shared_ptr<Node<ItemType>> headPtr;
	int itemCount;

	std::shared_ptr<Node<ItemType>> getPointerTo(const ItemType& target) const;
	std::shared_ptr<Node<ItemType>> getPointerTo(const ItemType& target, std::shared_ptr<Node<ItemType>>) const;
	void fillVector(std::vector<ItemType>& bagContents, std::shared_ptr<Node<ItemType>>) const;

public:
	LinkedBag();
	LinkedBag(const LinkedBag<ItemType>& aBag);
	virtual ~LinkedBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	std::vector<ItemType> toVector() const;
};

#include "LinkedBag.cpp"