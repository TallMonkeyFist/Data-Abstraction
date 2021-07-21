#pragma once

#include "Entry.h"
#include "NotFoundException.h"
#include "DictionaryInterface.h"
#include "PreconViolatedExcept.h"
#include <memory>

template <class KeyType, class ValueType>
class ArrayDictionary : public DictionaryInterface<KeyType, ValueType>
{
public:
	ArrayDictionary();
	ArrayDictionary(int maxNumberOfEntries);
	ArrayDictionary(const ArrayDictionary<KeyType, ValueType>& dictionary);

	virtual ~ArrayDictionary();

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
	static const int DEFAULT_CAPACITY = 21;
	std::unique_ptr<Entry<KeyType, ValueType>[]> entries;
	int entryCount;
	int maxEntries;

	void destroyDictionary();
	int findEntryIndex(int firstIndex, int lastIndex, const KeyType& searchKey) const;
};

#include "ArrayDictionary.cpp"