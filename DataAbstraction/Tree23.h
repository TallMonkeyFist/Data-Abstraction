#pragma once

#include <memory>
#include "BalancedTreeInterface.h"
#include "TriNode.h"

template <class ItemType>
class Tree23 : public BalancedTreeInterface<ItemType>
{

#define triNodePtr std::shared_ptr<TriNode<ItemType>>

public:
	Tree23();

	~Tree23();

	bool insert(const ItemType& anItem);
	bool contains(const ItemType& anItem) const;
	ItemType findEntry(const ItemType& anItem) const throw(NotFoundException);
	void traverse(void visit(const ItemType&)) const;

private:
	triNodePtr locateLeaf(const ItemType& anItem) const;
	void split(triNodePtr node);
};

#include "Tree23.cpp"