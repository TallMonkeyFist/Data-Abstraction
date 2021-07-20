#include "ArrayDictionary.h"

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::add(const KeyType& searchKey, const ValueType& newValue) throw(PreconViolatedExcept)
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