#pragma once
#include "BoxInterface.h"

template<class ItemType>

class PlainBox : public BoxInterface<ItemType>
{
protected:
	ItemType item;

public:
	PlainBox();

	PlainBox(const ItemType& theItem);

	virtual void setItem(const ItemType& theItem);

	virtual ItemType getItem() const;
};

#include "PlainBox.cpp"