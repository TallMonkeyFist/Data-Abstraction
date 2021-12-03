#pragma once

#include "NotFoundException.h"
#include "PreconViolatedExcept.h"

template<class ItemType>
class BalancedTreeInterface
{
	/**Inserts the unique item in the tree
	* @post If the item is unique, the item will be inserted
	* @param The unique entry to insert
	* @return true if the insert is successful
	*/
	bool insert(const ItemType& anItem) const = 0;

	/**Checks if the item is in the tree
	* @post The tree is unchanged
	* @param the unique entry to check for
	* @return true if the entry is in the tree
	*/
	bool contains(const ItemType& anItem) const = 0;

	/**Retrieves the item from the tree
	@post If the retrieval is successful, the item is returned
	@param target The entry to find
	@return The tree entry
	@throw NotFoundException if the entry does not exist.*/
	ItemType findItem(const ItemType& target) const throw(NotFoundException) = 0;

	/**
	* Traverses throught the tree in sorted order calling client function
	* on each entry
	* @post Client function is called once on each entry and tree is unchanged
	* @param Client's function
	*/
	void traverse(void visit(ItemType)) const = 0;
};