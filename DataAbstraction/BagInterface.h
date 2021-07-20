/** @file BagInterface.h */

#pragma once

#include <vector>

template <class ItemType>
class BagInterface
{
public:

	/** Gets the current number of entried in this bag
	@return  The integer number of entried currently in the bag.   */
	virtual int getCurrentSize() const = 0;

	/** Sees whether this bag is empty
	@return  True if the bag is empty, or false if not.   */
	virtual bool isEmpty() const = 0;

	/** Adds a new entry to this bag
	@post  If successful, newEntry is stored in the bag and
		the count of items in the bag has increased by 1.
	@param newEntry  Theobject to be added as a new entry.
	@return  True if addition was successful, or false if not.   */
	virtual bool add(const ItemType& newEntry) = 0;

	/** Removes one occurrence of the given entry from this bag, 
		 if possible
	@post  If successful, anEntry has been removed from the bag
		and the count of items in the bag has decreased by 1
	@param anEntry	The entry to be removed
	@return	True if removal was successful, or false if not.	*/
	virtual bool remove(const ItemType& anEntry) = 0;

	/** Removes all entries from this bag.
	@post Bag contains no items, and the count of items is 0.	*/
	virtual void clear() = 0;

	/** Counts the number of times a given entry appears in this bag.
	@param anEntry	The entry to be counted
	@return	The number of times anEntry appears in the bag	*/
	virtual int getFrequencyOf(const ItemType& anEntry) const = 0;

	/** Tests whether bag contains a given entry
	@param anEntry	The entry to locate
	@return	True if bag contains anEntry, or false otherwise.	*/
	virtual bool contains(const ItemType& anEntry) const = 0;

	/** Empties and then fills a given vector with all entries that
		are in the bag
	@return	A vector containing copies of all the entries in the bag.	*/
	virtual std::vector<ItemType> toVector() const = 0;

	/** Destroys this bag and frees its assigned memory.*/
	virtual ~BagInterface() { }
};