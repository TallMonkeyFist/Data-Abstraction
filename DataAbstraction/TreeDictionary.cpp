template<class KeyType, class ValueType>
TreeDictionary<KeyType, ValueType>::TreeDictionary()
{
	entryTree = BinarySearchTree<Entry<KeyType, ValueType>>();
}

template<class KeyType, class ValueType>
TreeDictionary<KeyType, ValueType>::TreeDictionary(const TreeDictionary<KeyType, ValueType>& dictionary)
{
	entryTree = BinarySearchTree<Entry<KeyType, ValueType>>(dictionary.entryTree);


}

template<class KeyType, class ValueType>
TreeDictionary<KeyType, ValueType>::~TreeDictionary()
{

}

template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::isEmpty() const
{
	return entryTree.isEmpty();
}

template<class KeyType, class ValueType>
int TreeDictionary<KeyType, ValueType>::getNumberOfEntries() const
{
	return entryTree.getNumberOfNodes();
}

template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::add(const KeyType& searchKey,
	const ValueType& newValue) throw(PreconViolatedExcept)
{
	Entry<KeyType, ValueType> newEntry = Entry<KeyType, ValueType>(searchKey, newValue);
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
	Entry<KeyType, ValueType> entry = Entry<KeyType, ValueType>(searchKey, ValueType());
	return entryTree.remove(entry);
}

template<class KeyType, class ValueType>
void TreeDictionary<KeyType, ValueType>::clear()
{
	entryTree.clear();
}


template <class KeyType, class ValueType>
ValueType TreeDictionary<KeyType, ValueType>::getValue(
	const KeyType& searchKey) const
	throw (NotFoundException)
{
	Entry<KeyType, ValueType> dummyEntry = Entry<KeyType, ValueType>(searchKey, ValueType());
	Entry<KeyType, ValueType> entry = entryTree.getEntry(dummyEntry);
	return entry.getValue();
}

template<class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::contains(const KeyType& searchKey) const
{
	Entry<KeyType, ValueType> entry = Entry<KeyType, ValueType>(searchKey, ValueType());
	return entryTree.contains(entry);
}

template <class KeyType, class ValueType>
void TreeDictionary<KeyType, ValueType>::traverse(void visit(ValueType&)) const
{
	std::cout << "Not Supported\n";
}

template <class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::replace(
	const KeyType& searchKey, const ValueType& newValue)
{
	Entry<KeyType, ValueType> newEntry = Entry<KeyType, ValueType>(searchKey, newValue);
	if (entryTree.contains(newEntry))
	{
		entryTree.remove(newEntry);
		entryTree.add(newEntry);
		return true;
	}
	return false;
}