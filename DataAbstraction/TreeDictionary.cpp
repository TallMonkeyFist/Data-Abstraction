template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::add(const KeyType& searchKey,
	const ValueType& newValue) throw(PreconViolatedExcept)
{
	Entry<KeyType, ValueType> newEntry = Entry(searchKey, newValue);
	if (!entryTree.contains(newEntry))
	{
		return entryTree.add(newEntry);
	}
	std::string message = "Attempt to add an entry whose search key exist in dictionary";
	throw(PreconViolatedExcept(message));
}

template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::remove(const KeyType& searchKey)
{
	Entry<KeyType, ValueType> entry = Entry(searchKey, ValueType());
	return entryTree.remove(entry);
}

template <class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::replace(
	const KeyType& searchKey, const ValueType& newValue)
{
	Entry<KeyType, ValueType> newEntry = Entry(searchKey, newValue);
	if (entryTree.contains(newEntry))
	{
		entryTree.remove(newEntry);
		entryTree.add(newEntry);
		return true;
	}
	return false;
}