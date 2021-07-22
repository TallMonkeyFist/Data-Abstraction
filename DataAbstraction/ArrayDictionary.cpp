#include "ArrayDictionary.h"

template <class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::ArrayDictionary() : maxEntries(DEFAULT_CAPACITY), entryCount(0)
{
	entries = std::make_unique<Entry<KeyType, ValueType>[]>(DEFAULT_CAPACITY);
}

template <class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::ArrayDictionary(int maxNumberOfEntries) : maxEntries(maxNumberOfEntries), entryCount(0)
{
	entries = std::make_unique<Entry<KeyType, ValueType>[]>(maxNumberOfEntries);
}

template <class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::ArrayDictionary(
	const ArrayDictionary<KeyType, ValueType>& dictionary) : 
	maxEntries(dictionary.maxEntries), entryCount(dictionary.entryCount)
{
	entries = std::make_unique<Entry<KeyType, ValueType>[]>(maxEntries);

	for (int i = 0; i < entryCount; i++)
	{
		entries[i] = Entry<KeyType, ValueType>(dictionary.entries[i].getKey(), 
			dictionary.entries[i].getValue());
	}
}

template <class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::~ArrayDictionary()
{
	destroyDictionary();
}

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::isEmpty() const
{
	return entryCount == 0;
}

template <class KeyType, class ValueType>
int ArrayDictionary<KeyType, ValueType>::getNumberOfEntries() const
{
	return entryCount;
}

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::add(
	const KeyType& searchKey, const ValueType& newValue)
	throw(PreconViolatedExcept)
{
	if (entryCount < maxEntries)
	{
		int index = entryCount;

		while ((index > 0) && (searchKey < entries[index - 1].getKey()))
		{
			entries[index] = entries[index - 1];
			index--;
		}
		
		if (searchKey != entries[index - 1].getKey())
		{
			entries[index] = Entry<KeyType, ValueType>(searchKey, newValue);
			entryCount++;
		}
		else
		{
			std::string message = "Attempt to add an entry whose search ket exists in the dictionary.";
			throw(PreconViolatedExcept(message));
		}
		return true;
	}
	return false;
}

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::remove(const KeyType& searchKey)
{
	int index = findEntryIndex(0, entryCount - 1, searchKey);
	if (index != -1)
	{
		for (int i = index; i < entryCount - 1; i++)
		{
			entries[i] = entries[i + 1];
		}
		entryCount--;
		return true;
	}
	return false;
}

template <class KeyType, class ValueType>
void ArrayDictionary<KeyType, ValueType>::clear()
{
	entryCount = 0;
}

template <class KeyType, class ValueType>
ValueType ArrayDictionary<KeyType, ValueType>::getValue(
	const KeyType& searchKey) const
	throw (NotFoundException)
{
	int index = findEntryIndex(0, entryCount - 1, searchKey);
	if (index != -1)
	{
		return entries[index].getValue();
	}
	else
	{
		std::string message = "Attempt to retrieve from a non-existant key";
		throw(NotFoundException(message));
	}
}

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::contains(const KeyType& searchKey) const
{
	return findEntryIndex(0, entryCount - 1, searchKey) != -1;
}

template <class KeyType, class ValueType>
void ArrayDictionary<KeyType, ValueType>::traverse(void visit(ValueType&)) const
{
	for (int i = 0; i < entryCount; i++)
	{
		ValueType value = entries[i].getValue();
		visit(value);
	}
}

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::replace(
	const KeyType& searchKey, const ValueType& newValue)
{
	for (int i = 0; i < entryCount; i++)
	{
		if (searchKey == entries[i].getKey())
		{
			entries[i].setValue(newValue);
			return true;
		}
	}
	return false;
}

template <class KeyType, class ValueType>
void ArrayDictionary<KeyType, ValueType>::destroyDictionary()
{
	entryCount = 0;
	entries = nullptr;
}

template <class KeyType, class ValueType>
int ArrayDictionary<KeyType, ValueType>::findEntryIndex(
	int firstIndex, int lastIndex, const KeyType& searchKey) const
{
	for (int i = firstIndex; i <= lastIndex; i++)
	{
		if (entries[i].getKey() == searchKey)
		{
			return i;
		}
	}
	return -1;
}