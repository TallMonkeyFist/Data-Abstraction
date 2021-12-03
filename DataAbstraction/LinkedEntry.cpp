#include "LinkedEntry.h"

template <class KeyType, class ValueType>
LinkedEntry<KeyType, ValueType>::LinkedEntry() : Entry<KeyType, ValueType>(), nextEntry(nullptr)
{
}

template <class KeyType, class ValueType>
LinkedEntry<KeyType, ValueType>::LinkedEntry(const KeyType& keyValue, 
	const ValueType& newValue) : Entry<KeyType, ValueType>(keyValue, newValue), nextEntry(nullptr)
{
}

template <class KeyType, class ValueType>
LinkedEntry<KeyType, ValueType>::LinkedEntry(const KeyType& keyValue,
	const ValueType& newValue, linkedEntryPtr next) : 
	Entry<KeyType, ValueType>(keyValue, newValue), nextEntry(next)
{
}

template<class KeyType, class ValueType>
LinkedEntry<KeyType, ValueType>::LinkedEntry(const LinkedEntry<KeyType, ValueType>& entry) :
	Entry<KeyType, ValueType>(entry.getKey(), entry.getValue())
{
	if (entry.getNext() == nullptr)
	{
		nextEntry = nullptr;
	}
	else
	{
		linkedEntryPtr next = std::make_shared<LinkedEntry<KeyType, ValueType>>
			(*entry.getNext());
		setNext(next);
	}
}

template <class KeyType, class ValueType>
LinkedEntry<KeyType, ValueType>::~LinkedEntry()
{
	nextEntry = nullptr;
}

template <class KeyType, class ValueType>
linkedEntryPtr LinkedEntry<KeyType, ValueType>::getNext() const
{
	return nextEntry;
}

template <class KeyType, class ValueType>
void LinkedEntry<KeyType, ValueType>::setNext(linkedEntryPtr nextPtr)
{
	nextEntry = nextPtr;
}

template <class KeyType, class ValueType>
bool LinkedEntry<KeyType, ValueType>::operator==(
	const LinkedEntry<KeyType, ValueType>& rhs) const
{
	return Entry<KeyType, ValueType>::getKey() == rhs.getKey();
}

template <class KeyType, class ValueType>
bool LinkedEntry<KeyType, ValueType>::operator!=(
	const LinkedEntry<KeyType, ValueType>& rhs) const
{
	return !(*this == rhs);
}

template <class KeyType, class ValueType>
bool LinkedEntry<KeyType, ValueType>::operator>(
	const LinkedEntry<KeyType, ValueType>& rhs) const
{
	return Entry<KeyType, ValueType>::getKey() > rhs.getKey();
}

template <class KeyType, class ValueType>
bool LinkedEntry<KeyType, ValueType>::operator>=(
	const LinkedEntry<KeyType, ValueType>& rhs) const
{
	return Entry<KeyType, ValueType>::getKey() >= rhs.getKey();
}

template <class KeyType, class ValueType>
bool LinkedEntry<KeyType, ValueType>::operator<(
	const LinkedEntry<KeyType, ValueType>& rhs) const
{
	return Entry<KeyType, ValueType>::getKey() < rhs.getKey();
}

template <class KeyType, class ValueType>
bool LinkedEntry<KeyType, ValueType>::operator<=(
	const LinkedEntry<KeyType, ValueType>& rhs) const
{
	return Entry<KeyType, ValueType>::getKey() <= rhs.getKey();
}