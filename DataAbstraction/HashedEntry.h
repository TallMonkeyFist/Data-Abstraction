#pragma once

#include "Entry.h"
#include <memory>

template <class KeyType, class ValueType>
class HashedEntry : public Entry<KeyType, ValueType>
{
public:
	HashedEntry();
	HashedEntry(const KeyType& searchKey, const ValueType& newValue);
	HashedEntry(const KeyType& searchKey, const ValueType& newValue,
		std::shared_ptr<HashedEntry<KeyType, ValueType>> nextEntryPtr);

	void setNext(std::shared_ptr<HashedEntry<KeyType, ValueType>> nextEntryPtr);

	auto getNext() const;

private:
	std::shared_ptr<HashedEntry<KeyType, ValueType>> nextPtr;
};

#include "HashedEntry.cpp"