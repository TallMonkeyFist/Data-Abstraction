#pragma once

#include <memory>

#include "DictionaryInterface.h"
#include "HashedEntry.h"

template <class KeyType, class ValueType>
using hashTableType = std::shared_ptr<HashedEntry<KeyType, ValueType>>[];

template <class KeyType, class ValueType>
class HashedDictionary : public DictionaryInterface<KeyType, ValueType>
{
private:
	static const int DEFAULT_CAPACITY = 101;

public:
	HashedDictionary();
	HashedDictionary(int size);
	HashedDictionary(const HashedDictionary<KeyType, ValueType>& dictionary);

	~HashedDictionary();

	bool isEmpty() const;
	int getNumberOfEntries() const;
	bool add(const KeyType& searchKey, const ValueType& newValue) throw(PreconViolatedExcept);
	bool remove(const KeyType& searchKey);
	void clear();
	ValueType getValue(const KeyType& searchKey) const throw(NotFoundException);
	bool contains(const KeyType& searchKey) const;

	void traverse(void visit(ValueType&)) const;

	bool replace(const KeyType& searchKey, const ValueType& newValue);

private:
	std::unique_ptr<hashTableType<KeyType, ValueType>> hashTable;

	int entryCount;
	int hashTableSize;

	int getHashIndex(KeyType searchKey) const;
};

#include "HashedDictionary.cpp"