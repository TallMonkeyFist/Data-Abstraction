#pragma once

template <class KeyType, class ValueType>
class Entry
{
public:
	Entry();
	Entry(const KeyType& keyValue, const ValueType& newValue);
	ValueType getValue() const;
	KeyType getKey() const;
	void setValue(const ValueType& newValue);

	bool operator==(const Entry<KeyType, ValueType>& rightHandValue) const;
	bool operator>(const Entry<KeyType, ValueType>& rightHandValue) const;
protected:
	void setKey(const KeyType& searchKey);
private:
	KeyType key;
	ValueType value;
};

#include "Entry.cpp"