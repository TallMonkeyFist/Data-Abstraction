#pragma once

#include "DictionaryInterface.h"
#include "BinarySearchTree.h"
#include "Entry.h"
#include "NotFoundException.h"
#include "PreconViolatedExcept.h"
#include <functional>

template <class KeyType, class ValueType>
class TreeDictionary : public DictionaryInterface<KeyType, ValueType>
{
public:
	TreeDictionary();
	TreeDictionary(const TreeDictionary<KeyType, ValueType>& dictionary);

	virtual ~TreeDictionary();

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
	BinarySearchTree<Entry<KeyType, ValueType>> entryTree;
};

#include "TreeDictionary.cpp"