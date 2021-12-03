#pragma once

#include <memory>


template <class ItemType>
class TriNode
{

#define triNodePtr std::shared_ptr<TriNode<ItemType>>

public:
	TriNode();

	bool isLeaf() const;
	bool isTwoNode() const;
	bool isThreeNode() const;

	ItemType getSmallItem() const;
	ItemType getLargeItem() const;

	void setSmallItem(const ItemType& anItem);
	void setLargeItem(const ItemType& anItem);
	auto getLeftChildPtr() const;
	auto getMidChildPtr() const;
	auto getRightChildPtr() const;

	void setLeftChildPtr(triNodePtr leftPtr);
	void setMidChildPtr(triNodePtr midPtr);
	void setRightChildPtr(triNodePtr rightPtr);

private:
	ItemType smallItem;
	ItemType largeItem;
	std::shared_ptr<TriNode<ItemType>> leftChildPtr;
	std::shared_ptr<TriNode<ItemType>> midChildPtr;
	std::shared_ptr<TriNode<ItemType>> rightChildPtr;
};

#include "TriNode.cpp"