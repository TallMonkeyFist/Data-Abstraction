#pragma once

#include "PlainBox.h"

template<class ItemType>
class MagicBox : public PlainBox<ItemType>
{
private:
	bool firstItemStored;

public:
	MagicBox();
	MagicBox(const ItemType& theItem);
	void setItem(const ItemType& theItem) override final;
};

#include "MagicBox.cpp"