template <class KeyType, class ValueType>
SortedLinkedDictionary<KeyType, ValueType>::SortedLinkedDictionary()
{
	entryList = LinkedSortedList<Entry<KeyType, ValueType>>();
}

template <class KeyType, class ValueType>
SortedLinkedDictionary<KeyType, ValueType>::SortedLinkedDictionary(const SortedLinkedDictionary<KeyType, ValueType>& dictionary)
{
	entryList = LinkedSortedList<Entry<KeyType, ValueType>>(dictionary.entryList);
}

template<class KeyType, class ValueType>
SortedLinkedDictionary<KeyType, ValueType>::~SortedLinkedDictionary()
{
	entryList.~LinkedSortedList();
}

template<class KeyType, class ValueType>
bool SortedLinkedDictionary<KeyType, ValueType>::isEmpty() const
{
	return entryList.isEmpty();
}

template<class KeyType, class ValueType>
int SortedLinkedDictionary<KeyType, ValueType>::getNumberOfEntries() const
{
	return entryList.getLength();
}

template<class KeyType, class ValueType>
bool SortedLinkedDictionary<KeyType, ValueType>::add(const KeyType& searchKey, const ValueType& newValue) throw(PreconViolatedExcept)
{
	if (entryList.getIndex(Entry<KeyType, ValueType>(searchKey, newValue)) == -1)
	{
		return entryList.insertSorted(Entry<KeyType, ValueType>(searchKey, newValue));
	}
	std::string message = "Attempt to add an entry whose search ket exists in the dictionary.";
	throw PreconViolatedExcept(message);
}

template<class KeyType, class ValueType>
bool SortedLinkedDictionary<KeyType, ValueType>::remove(const KeyType& searchKey)
{
	int index = entryList.getIndex(Entry<KeyType, ValueType>(searchKey, ValueType()));
	if (index == -1)
	{
		return false;
	}
	return entryList.remove(index);
}

template<class KeyType, class ValueType>
void SortedLinkedDictionary<KeyType, ValueType>::clear()
{
	entryList.clear();
}

template<class KeyType, class ValueType>
ValueType SortedLinkedDictionary<KeyType, ValueType>::getValue(const KeyType& searchKey) const
{
	int index = entryList.getIndex(Entry<KeyType, ValueType>(searchKey, ValueType()));
	if (index == -1)
	{
		std::string message = "Attempt to retrieve from a non-existant key";
		throw(NotFoundException(message));
	}
	return entryList.getEntry(index).getValue();
}

template<class KeyType, class ValueType>
bool SortedLinkedDictionary<KeyType, ValueType>::contains(const KeyType& searchKey) const
{
	return entryList.getIndex(Entry<KeyType, ValueType>(searchKey, ValueType())) != -1;
}

template<class KeyType, class ValueType>
void SortedLinkedDictionary<KeyType, ValueType>::traverse(void visit(ValueType&)) const
{
	for (int i = 0; i < entryList.getLength(); i++)
	{
		ValueType value = entryList.getEntry(i).getValue();
		visit(value);
	}
}

template<class KeyType, class ValueType>
bool SortedLinkedDictionary<KeyType, ValueType>::replace(const KeyType& searchKey, const ValueType& newValue)
{
	Entry<KeyType, ValueType> newEntry(searchKey, newValue);
	int index = entryList.getIndex(newEntry);
	if (index == -1)
	{
		return false;
	}
	entryList.remove(index);
	return entryList.insertSorted(newEntry);;
}