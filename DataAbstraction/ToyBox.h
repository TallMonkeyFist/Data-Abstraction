#pragma once

#include "PlainBox.h"

enum Color { BLACK, RED, BLUE, GREEN, YELLOW, WHITE };

template<class ItemType>
class ToyBox : public PlainBox<ItemType>
{
private:
	Color boxColor;
public:
	ToyBox();
	ToyBox(const Color& theColor);
	ToyBox(const ItemType& theItem, const Color& theColor);
	Color getColor() const;
};

#include "ToyBox.cpp"