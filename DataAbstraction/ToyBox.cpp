#include "ToyBox.h"

template<class ItemType>
ToyBox<ItemType>::ToyBox() : boxColor(BLACK)
{

}

template<class ItemType>
ToyBox<ItemType>::ToyBox(const Color& theColor) : boxColor(theColor)
{

}

template<class ItemType>
ToyBox<ItemType>::ToyBox(const ItemType& theItem, const Color& theColor) : PlainBox<ItemType>(theItem), boxColor(theColor)

{

}

template<class ItemType>
Color ToyBox<ItemType>::getColor() const
{
    return boxColor;
}