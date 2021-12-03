#include "LinkedSortedDictionary.h"
template<class KeyType, class ValueType>
LinkedSortedDictionary<KeyType, ValueType>::LinkedSortedDictionary() : length(0), headPtr(nullptr)
{
}

template<class KeyType, class ValueType>
LinkedSortedDictionary<KeyType, ValueType>::LinkedSortedDictionary(
	const KeyType& keyValue, const ValueType& newValue) : length(1)
{
	headPtr = std::make_shared<LinkedEntry<KeyType, ValueType>>(keyValue, newValue);
}

template<class KeyType, class ValueType>
LinkedSortedDictionary<KeyType, ValueType>::LinkedSortedDictionary(
	const LinkedSortedDictionary<KeyType, ValueType>& dictionary) : length(dictionary.length)
{
	if (dictionary.headPtr == nullptr)
	{
		headPtr = nullptr;
	}
	else
	{
		headPtr = std::make_shared<
			LinkedEntry<KeyType, ValueType>>(*dictionary.headPtr);
	}
}

template<class KeyType, class ValueType>
LinkedSortedDictionary<KeyType, ValueType>::~LinkedSortedDictionary()
{
	clear();
}

template<class KeyType, class ValueType>
bool LinkedSortedDictionary<KeyType, ValueType>::isEmpty() const
{
	return headPtr == nullptr;
}

template<class KeyType, class ValueType>
int LinkedSortedDictionary<KeyType, ValueType>::getNumberOfEntries() const
{
	return length;
}

template<class KeyType, class ValueType>
bool LinkedSortedDictionary<KeyType, ValueType>::add(const KeyType& searchKey, const ValueType& newValue) throw(PreconViolatedExcept)
{
	if (headPtr == nullptr)
	{
		headPtr = std::make_shared<LinkedEntry<KeyType, ValueType>>(searchKey, newValue);
		length++;
		return true;
	}
	LinkedEntry<KeyType, ValueType> entry(searchKey, newValue);
	if (*headPtr == entry)
	{
		std::string message = "Attempt to add entry that already exist";
		throw PreconViolatedExcept(message);
	}
	if (*headPtr > entry)
	{
		headPtr = std::make_shared<LinkedEntry<KeyType, ValueType>>
			(searchKey, newValue, headPtr);
		length++;
		return true;
	}
	linkedEntryPtr prevPtr = getPrevPtr(searchKey);
	if (prevPtr != nullptr)
	{
		if (prevPtr->getNext() != nullptr && *(prevPtr->getNext()) == entry)
		{
			std::string message = "Attempt to add entry that already exist";
			throw PreconViolatedExcept(message);
		}
		linkedEntryPtr newEntry = std::make_shared<LinkedEntry<KeyType, ValueType>>
			(searchKey, newValue, prevPtr->getNext());
		prevPtr->setNext(newEntry);
		length++;
		return true;
	}
	return false;
}

template<class KeyType, class ValueType>
bool LinkedSortedDictionary<KeyType, ValueType>::remove(const KeyType& searchKey)
{
	LinkedEntry<KeyType, ValueType> toRemove(searchKey, ValueType());
	if (*headPtr == toRemove)
	{
		headPtr = headPtr->getNext();
		length--;
		return true;
	}
	linkedEntryPtr prevPtr = getPrevPtr(searchKey);
	if (prevPtr != nullptr && prevPtr->getNext() != nullptr && 
		*(prevPtr->getNext()) == toRemove)
	{
		prevPtr->setNext(prevPtr->getNext()->getNext());
		length--;
		return true;
	}
	return false;
}

template<class KeyType, class ValueType>
void LinkedSortedDictionary<KeyType, ValueType>::clear()
{
	headPtr = nullptr;
	length = 0;
}

template<class KeyType, class ValueType>
ValueType LinkedSortedDictionary<KeyType, ValueType>::getValue(const KeyType& searchKey) const throw(NotFoundException)
{
	linkedEntryPtr entry = getPtr(searchKey);
	if (entry == nullptr)
	{
		std::string message = "Attempt to get value of non-existent entry";
		throw NotFoundException(message);
	}
	return entry->getValue();
}

template<class KeyType, class ValueType>
bool LinkedSortedDictionary<KeyType, ValueType>::contains(const KeyType& searchKey) const
{
	return getPtr(searchKey) != nullptr;
}

template<class KeyType, class ValueType>
void LinkedSortedDictionary<KeyType, ValueType>::traverse(void visit(ValueType&)) const
{
	linkedEntryPtr currPtr = headPtr;
	while (currPtr != nullptr)
	{
		ValueType value = currPtr->getValue();
		visit(value);
		currPtr = currPtr->getNext();
	}
}

template<class KeyType, class ValueType>
bool LinkedSortedDictionary<KeyType, ValueType>::replace(const KeyType& searchKey, const ValueType& newValue)
{
	linkedEntryPtr entry = getPtr(searchKey);
	if (entry != nullptr)
	{
		entry->setValue(newValue);
		return true;
	}
	return false;
}

template<class KeyType, class ValueType>
linkedEntryPtr LinkedSortedDictionary<KeyType, ValueType>::getPrevPtr(const KeyType& searchKey) const
{
	LinkedEntry<KeyType, ValueType> entry(searchKey, ValueType());
	if (isEmpty() || *headPtr == entry)
	{
		return nullptr;
	}
	linkedEntryPtr currPtr = headPtr;
	while (currPtr->getNext() != nullptr)
	{
		if (*(currPtr->getNext()) >= entry)
		{
			return currPtr;
		}
		currPtr = currPtr->getNext();
	}
	return currPtr;
}

template<class KeyType, class ValueType>
linkedEntryPtr LinkedSortedDictionary<KeyType, ValueType>::getPtr(const KeyType& searchKey) const
{
	LinkedEntry<KeyType, ValueType> entry(searchKey, ValueType());
	if (isEmpty() || *headPtr > entry)
	{
		return nullptr;
	}
	linkedEntryPtr currPtr = headPtr;
	while (currPtr != nullptr)
	{
		if (*currPtr == entry)
		{
			return currPtr;
		}
		if (*currPtr > entry)
		{
			break;
		}
		currPtr = currPtr->getNext();
		
	}
	return nullptr;
}