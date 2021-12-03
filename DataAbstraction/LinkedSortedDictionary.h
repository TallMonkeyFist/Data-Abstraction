#pragma once

#include "NotFoundException.h"
#include "DictionaryInterface.h"
#include "PreconViolatedExcept.h"
#include "LinkedEntry.h"

template<class KeyType, class ValueType>
class LinkedSortedDictionary : public DictionaryInterface<KeyType, ValueType>
{
public:
	LinkedSortedDictionary();
	LinkedSortedDictionary(const KeyType& keyValue, const ValueType& newValue);
	LinkedSortedDictionary(const LinkedSortedDictionary<KeyType, ValueType>& dictionary);

	~LinkedSortedDictionary();

	bool isEmpty() const;
	int getNumberOfEntries() const;
	bool add(const KeyType& searchKey, const ValueType& newValue) throw(PreconViolatedExcept);
	bool remove(const KeyType& searchKey);
	void clear();
	ValueType getValue(const KeyType& searchKey) const throw(NotFoundException);
	bool contains(const KeyType& searchKey) const;

	/**Traverses the entries in this dictionary in sorted search-key order
	and calls a given client function once for the value in each entry.*/
	void traverse(void visit(ValueType&)) const;

	bool replace(const KeyType& searchKey, const ValueType& newValue);

private:
	std::shared_ptr<LinkedEntry<KeyType, ValueType>> headPtr;
	int length;
	linkedEntryPtr getPrevPtr(const KeyType& searchKey) const;
	linkedEntryPtr getPtr(const KeyType& searchKey) const;
};

#include "LinkedSortedDictionary.cpp"