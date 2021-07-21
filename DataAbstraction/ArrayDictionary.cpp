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
		entries[i] = Entry(dictionary.entries[i].getKey(), 
			dictionary.entries[i].getValue());
	}
}

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::add(
	const KeyType& searchKey, const ValueType& newValue)
	throw(PreconViolatedExcept)
{
	if (entryCount < maxEntries)
	{
		int index = entryCount;

		while ((index > 0) && (searchKey < items[index - 1].getKey()))
		{
			items[index] = items[index - 1];
			index--;
		}
		
		if (searchKey != items[index - 1].getKey())
		{
			items[index] = Entry<KeyType, ValueType>(searchKey, newValue);
			itemCount++;
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
bool ArrayDictionary<KeyType, ValueType>::replace(
	const KeyType& searchKey, const ValueType& newValue)
{
	for (int i = 0; i < entryCount; i++)
	{
		if (searchKey == items[i].getKey())
		{
			items[i].setValue(newValue);
			return true;
		}
	}
	return false;
}