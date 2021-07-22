template <class KeyType, class ValueType>
HashedEntry<KeyType, ValueType>::HashedEntry() : Entry<KeyType, ValueType>(KeyType(), ValueType()), nextPtr(nullptr)
{
}

template <class KeyType, class ValueType>
HashedEntry<KeyType, ValueType>::HashedEntry(const KeyType& searchKey,
	const ValueType& newValue) : Entry<KeyType, ValueType>(searchKey, newValue), nextPtr(nullptr)
{
}

template <class KeyType, class ValueType>
HashedEntry<KeyType, ValueType>::HashedEntry(const KeyType& searchKey,
	const ValueType& newValue,
	std::shared_ptr<HashedEntry<KeyType, ValueType>> nextEntryPtr) : 
		Entry<KeyType, ValueType>(searchKey, newValue), nextPtr(nextEntryPtr)
{

}


template <class KeyType, class ValueType>
void HashedEntry<KeyType, ValueType>::setNext(
	std::shared_ptr<HashedEntry<KeyType, ValueType>> nextEntryPtr)
{
	nextPtr = nextEntryPtr;
}

template <class KeyType, class ValueType>
auto HashedEntry<KeyType, ValueType>::getNext() const
{
	return nextPtr;
}