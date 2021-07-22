#pragma once

#include "NotFoundException.h"

template <class KeyType, class ValueType>
class DictionaryInterface
{
public:
	/**Sees whether this dictionary is empty.
	@return True if the dictionary is empty;
		otherwise returns false*/
	virtual bool isEmpty() const = 0;

	/**Gets the number of entries in this dictionary.
	@return The number of entries in the dictionary*/
	virtual int getNumberOfEntries() const = 0;

	/**Adds a new search key and associated value to this dictionary.
	@pre The new search key differs from all search keys presently
		in the dictionary
	@post If the addition is successful, the new key-value pair is in its
		proper position within the dictionary
	@param searchKey The search key associated with the value to be added.
	@param newValue The value to be added
	@return True if the entry was successfully added, or false if not*/
	virtual bool add(const KeyType& searchKey, const ValueType& newValue) = 0;

	/**Removes a key-value pair from this dictionary.
	@post If the entry whose search key equals search key existed in the
		dictionary, the entry was removed
	@param searchKey The search key of the entry to be removed
	@return True if the entry was successfully removed, or false if not*/
	virtual bool remove(const KeyType& searchKey) = 0;

	/**Removes all entries from this dictionary*/
	virtual void clear() = 0;

	/**Retrieves the value in this dictionary whose search key is given
	@post If the rettrieval is successful, the value is returned
	@param searchKey The search key of the value to be retrieved
	@return The value associated with the search key.
	@throw NotFoundException if the key-value pair does not exist.*/
	virtual ValueType getValue(const KeyType& searchKey) const throw(NotFoundException) = 0;

	/**Sees whether this ductionary contains an entry with a given search key.
	@post The dictionary is unchanged.
	@param searchKey The given search key.
	@return True if an entry with the given search key exist in the dictionary.*/
	virtual bool contains(const KeyType& searchKey) const = 0;

	/**Traverses this dictionary and calls a given client function once
		for each entry
	@post The given function's action occurs once for each entry in the dictionary and possibly alters the entry.
	@param visit A client function*/
	virtual void traverse(void visit(ValueType&)) const = 0;

	/**Replaces the entry for a given key if possible
	* @post If the replacement is successful, the value for the key will be
	*	updated to be the provided value
	* @param searchKey The search key associated with the value to be added.
	* @param newValue The value to replace the existing value
	* @return True if the entry was successfully replaced, or false if not
	*/
	virtual bool replace(const KeyType& searchKey, const ValueType& newValue) = 0;

	virtual ~DictionaryInterface() { }
};