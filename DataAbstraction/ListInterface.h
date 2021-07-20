#pragma once

template <class ItemType>
class ListInterface
{
public:
	/** Sees whether this list is empty.
	@return	True is the list is empty; otherwise returns false.*/
	virtual bool isEmpty() const = 0;
	/** Gets the current number of entries in this list.
	@return	The integer number of entries currently in the list.*/
	virtual int getLength() const = 0;
	/** Inserts an entry into this list at a given index.
	@pre None
	@post	If 0 <= atIndex <= getLength() and the insertion is 
		successful, newEntry is at the given position in the list,
		other entries are renumbered accordingly, and the returned
		value is true
	@param atIndex: The list index at which to insert newEntry
	@param newEntry: The entry to insert into the list
	@return	True if the insertion is successful, or false if not.*/
	virtual bool insert(int atIndex, const ItemType& newEntry) = 0;
	/** Removes the entry at a given index from this list
	@pre None
	@post If 0 <= atIndex < getLength() and the removal is successful,
		the entry at the given index is removed, other
		items are renumbered accordingly, and the returned value is true
	@param atIndex: the list index at the entry to remove
	@return	True if the removal is successful, or false if not*/
	virtual bool remove(int atIndex) = 0;
	/**Removes all entries from this list
	@post The list contains no entries and thee count of items is 0.*/
	virtual void clear() = 0;
	/** Gets the entry at the given index in this list
	@pre 0 <= anIndex < getLength().
	@post The desired entry had been returned
	@param atIndex: the list index of the desired entry.
	@return The entry at the given position*/
	virtual ItemType getEntry(int atIndex) const = 0;
	/** Replaces the entry at the given index in this list
	@pre 0 <= anIndex < getLength().
	@post The entry at atIndex is newEntry
	@param atIndex: the list index of the entry to replace.
	@param newEntry: The replacement entry.
	@return The replaced entry*/
	virtual ItemType replace(int atIndex, const ItemType& newEntry) = 0;

	/**Destroys this list and frees its assigned memory*/
	virtual ~ListInterface() {}
};