#include "PlainBox.h"

template<class ItemType>
PlainBox<ItemType>::PlainBox()
{

}

template<class ItemType>
PlainBox<ItemType>::PlainBox(const ItemType& theItem) : item(theItem)
{

}

template<class ItemType>
void PlainBox<ItemType>::setItem(const ItemType& theItem)
{
	item = theItem;
}

template<class ItemType>
ItemType PlainBox<ItemType>::getItem() const
{
	return item;
}