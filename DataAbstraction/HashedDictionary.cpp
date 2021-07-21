template <class KeyType, class ValueType>
bool HashedDictionary<KeyType, ValueType>::add(const KeyType& searchKey,
	const ValueType& newValue)
{
	std::shared_ptr<HashedEntry<KeyType, ValueType>> entryToAddPtr = 
		std::make_shared<HashedEntry<KeyType, ValueType>>(searchKey, newValue);
	int index = getHashIndex(searchKey);

	if (hashTable[index] == nullptr)
	{
		hashTable[index] = entryToAddPtr;
	}
	else
	{
		entryToAddPtr->setNext(hashTable[index]);
		hashTable[index] = entryToAddPtr;
	}
	return true;
}

template <class KeyType, class ValueType>
bool HashedDictionary<KeyType, ValueType>::remove(const KeyType& searchKey)
{
	int index = getHashIndex(searchKey);

	if (hashTable[index] != nullptr)
	{
		if (hashTable[index]->getKey() == searchKey)
		{
			hashTable[index] = hashTable[index]->getNext();
		}
		else
		{
			auto prevPtr = hashTable[index];
			auto currPtr = prevPtr->getNext();

			while (currPtr != nullPtr)
			{
				if (currPtr->getKey() == searchKey)
				{
					prevPtr->setNext(currPtr->getNext());
					currPtr->setNext(nullptr);
					return true;
				}
				prevPtr = currPtr;
				currPtr = currPtr->getNext();
			}
		}
	}

	return false;
}

template <class KeyType, class ValueType>
bool HashedDictionary<KeyType, ValueType>::replace(
	const KeyType& searchKey, const ValueType& newValue)
{
	int index = getHashIndex(searchKey);

	auto currPtr = hashTable[index];

	while (currPtr != nullptr)
	{
		if (currPtr->getKey() == searchKey)
		{
			currPtr->setValue(newValue);
			return true;
		}
		currPtr = currPtr->getNext();
	}

	return false;
}