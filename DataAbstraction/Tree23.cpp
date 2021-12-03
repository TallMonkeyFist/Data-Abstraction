#include "Tree23.h"
template <class ItemType>
bool Tree23<ItemType>::insert(const ItemType& anItem)
{

}

template<class ItemType>
bool Tree23<ItemType>::contains(const ItemType& anItem) const
{
	return false;
}

template<class ItemType>
ItemType Tree23<ItemType>::findEntry(const ItemType& anItem) const
{
	return ItemType();
}

template<class ItemType>
void Tree23<ItemType>::traverse(void visit(const ItemType&)) const
{

}

template<class ItemType>
triNodePtr Tree23<ItemType>::locateLeaf(const ItemType& anItem) const
{
	return triNodePtr();
}

template<class ItemType>
void Tree23<ItemType>::split(triNodePtr node)
{
	node->setSmallItem(nullptr);
}