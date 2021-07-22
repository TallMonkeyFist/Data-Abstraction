#include <functional>

template <class KeyType, class ValueType>
HashedDictionary<KeyType, ValueType>::HashedDictionary() : 
	entryCount(0), hashTableSize(DEFAULT_CAPACITY)
{
	hashTable = std::make_unique<hashTableType<KeyType, ValueType>>(hashTableSize);
}

template <class KeyType, class ValueType>
HashedDictionary<KeyType, ValueType>::HashedDictionary(int size) : 
	entryCount(0), hashTableSize(size)
{
	hashTable = std::make_unique<hashTableType<KeyType, ValueType>>(hashTableSize);
}

template <class KeyType, class ValueType>
HashedDictionary<KeyType, ValueType>::HashedDictionary(
	const HashedDictionary<KeyType, ValueType>& dictionary) :
	entryCount(dictionary.entryCount), hashTableSize(dictionary.hashTableSize)
{
	hashTable = std::make_unique<hashTableType<KeyType, ValueType>>(hashTableSize);
	for (int i = 0; i < hashTableSize; i++)
	{
		std::shared_ptr<HashedEntry<KeyType, ValueType>> currPtr = nullptr;
		auto currCopyPtr = dictionary.hashTable[i];
		if (currCopyPtr != nullptr)
		{
			currPtr = std::make_shared<HashedEntry<KeyType, ValueType>>(
				currCopyPtr->getKey(), currCopyPtr->getValue());
			currCopyPtr = currCopyPtr->getNext();
			hashTable[i] = currPtr;
		}
		while (currCopyPtr != nullptr)
		{
			auto nextPtr = std::make_shared<HashedEntry<KeyType, ValueType>>(
				currCopyPtr->getKey(), currCopyPtr->getValue());;
			currPtr->setNext(nextPtr);
			currPtr = currPtr->getNext();
			currCopyPtr = currCopyPtr->getNext();
		}
	}
}

template <class KeyType, class ValueType>
HashedDictionary<KeyType, ValueType>::~HashedDictionary()
{
	for (int i = 0; i < hashTableSize; i++)
	{
		hashTable[i] = nullptr;
	}
	hashTable = nullptr;
}

template <class KeyType, class ValueType>
bool HashedDictionary<KeyType, ValueType>::isEmpty() const
{
	return entryCount == 0;
}

template <class KeyType, class ValueType>
int HashedDictionary<KeyType, ValueType>::getNumberOfEntries() const
{
	return entryCount;
}

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
	entryCount++;
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
			entryCount--;
			return true;
		}
		else
		{
			auto prevPtr = hashTable[index];
			auto currPtr = prevPtr->getNext();

			while (currPtr != nullptr)
			{
				if (currPtr->getKey() == searchKey)
				{
					prevPtr->setNext(currPtr->getNext());
					currPtr->setNext(nullptr);
					entryCount--;
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
void HashedDictionary<KeyType, ValueType>::clear()
{
	for (int i = 0; i < hashTableSize; i++)
	{
		hashTable[i].reset();
	}
	entryCount = 0;
}

template <class KeyType, class ValueType>
ValueType HashedDictionary<KeyType, ValueType>::getValue(
	const KeyType& searchKey) const
	throw (NotFoundException)
{
	int index = getHashIndex(searchKey);
	auto currPtr = hashTable[index];

	while (currPtr != nullptr)
	{
		if (currPtr->getKey() == searchKey)
		{
			return currPtr->getValue();
		}
		currPtr = currPtr->getNext();
	}

	std::string message = "Attempt to retrieve from a non-existant key";
	throw(NotFoundException(message));
}

template <class KeyType, class ValueType>
bool HashedDictionary<KeyType, ValueType>::contains(
	const KeyType& searchKey) const
{
	int index = getHashIndex(searchKey);
	auto currPtr = hashTable[index];
	while (currPtr != nullptr)
	{
		if (currPtr->getKey() == searchKey)
		{
			return true;
		}
		currPtr = currPtr->getNext();
	}
	return false;
}

template <class KeyType, class ValueType>
void HashedDictionary<KeyType, ValueType>::traverse(void visit(ValueType&)) const
{
	for (int i = 0; i < hashTableSize; i++)
	{
		auto currPtr = hashTable[i];

		while (currPtr != nullptr)
		{
			ValueType value = currPtr->getValue();
			visit(value);
			currPtr = currPtr->getNext();
		}
	}
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

template <class KeyType, class ValueType>
int HashedDictionary<KeyType, ValueType>::getHashIndex(KeyType searchKey) const
{
	std::hash<KeyType> hash;
	int hashIndex = hash(searchKey);
	if (hashIndex < 0)
		hashIndex *= -1;
	return hashIndex % hashTableSize;
}