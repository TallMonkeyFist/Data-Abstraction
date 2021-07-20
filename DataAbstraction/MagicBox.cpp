#include "MagicBox.h"

template<class ItemType>
MagicBox<ItemType>::MagicBox() : firstItemStored(false)
{

}

template<class ItemType>
MagicBox<ItemType>::MagicBox(const ItemType& theItem) : firstItemStored(false)
{
    setItem(theItem);
}

template<class ItemType>
void MagicBox<ItemType>::setItem(const ItemType& theItem)
{
    if (!firstItemStored)
    {
        PlainBox<ItemType>::item = theItem;
        firstItemStored = true;
    }
}