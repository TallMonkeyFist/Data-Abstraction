#pragma once

#include "Entry.h"
#include "LinkedSortedList.h"
#include "NotFoundException.h"
#include "DictionaryInterface.h"
#include "PreconViolatedExcept.h"

template <class KeyType, class ValueType>
class SortedLinkedDictionary : public DictionaryInterface<KeyType, ValueType>
{
public:
	SortedLinkedDictionary();
	SortedLinkedDictionary(const SortedLinkedDictionary<KeyType, ValueType>& dictionary);

	~SortedLinkedDictionary();

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
	LinkedSortedList<Entry<KeyType, ValueType>> entryList;
};

#include "SortedLinkedDictionary.cpp"