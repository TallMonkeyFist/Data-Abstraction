template <class KeyType, class ValueType>
HashedEntry<KeyType, ValueType>::HashedEntry()
{
}

template <class KeyType, class ValueType>
HashedEntry<KeyType, ValueType>::HashedEntry(const KeyType& searchKey,
	const ValueType& newValue) : Entry<KeyType, ValueType>(searchKey, newValue)
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