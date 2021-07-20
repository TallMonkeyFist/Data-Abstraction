#pragma once

template <class ItemType>
class BoxInterface
{
public:
	virtual void setItem(const ItemType& theItem) = 0;
	virtual ItemType getItem() const = 0;
	virtual ~BoxInterface() { }
};