#pragma once

#include "Entry.h"
#include <memory>


template <class KeyType, class ValueType>
class LinkedEntry : public Entry<KeyType, ValueType>
{
public:
#define linkedEntryPtr std::shared_ptr<LinkedEntry<KeyType, ValueType>>

	LinkedEntry();
	LinkedEntry(const KeyType& keyValue, const ValueType& newValue);
	LinkedEntry(const KeyType& keyValue, const ValueType& newValue, 
		linkedEntryPtr nextEntry);
	LinkedEntry(const LinkedEntry<KeyType, ValueType>& entry);

	~LinkedEntry();

	void setNext(linkedEntryPtr nextEntry);
	linkedEntryPtr getNext() const;

	bool operator==(const LinkedEntry<KeyType, ValueType>& rhs) const;
	bool operator!=(const LinkedEntry<KeyType, ValueType>& rhs) const;
	bool operator>(const LinkedEntry<KeyType, ValueType>& rhs) const;
	bool operator>=(const LinkedEntry<KeyType, ValueType>& rhs) const;
	bool operator<(const LinkedEntry<KeyType, ValueType>& rhs) const;
	bool operator<=(const LinkedEntry<KeyType, ValueType>& rhs) const;

private:
	linkedEntryPtr nextEntry;
};

#include "LinkedEntry.cpp"