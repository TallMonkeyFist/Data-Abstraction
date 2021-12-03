template <class ItemType>
TriNode<ItemType>::TriNode()
{
	leftChildPtr = rightChildPtr = midChildPtr = nullptr;
}

template <class ItemType>
bool TriNode<ItemType>::isLeaf() const
{
	return leftChildPtr == nullptr && rightChildPtr == nullptr && 
		midChildPtr == nullptr;
}

template <class ItemType>
bool TriNode<ItemType>::isTwoNode() const
{
	return leftChildPtr != nullptr && rightChildPtr == nullptr &&
		midChildPtr != nullptr;
}

template <class ItemType>
bool TriNode<ItemType>::isThreeNode() const
{
	return leftChildPtr != nullptr && rightChildPtr != nullptr &&
		midChildPtr != nullptr;
}

template <class ItemType>
ItemType TriNode<ItemType>::getSmallItem() const
{
	return smallItem;
}

template <class ItemType>
ItemType TriNode<ItemType>::getLargeItem() const
{
	return largeItem;
}

template <class ItemType>
void TriNode<ItemType>::setSmallItem(const ItemType& anItem)
{
	smallItem = anItem;
}

template <class ItemType>
void TriNode<ItemType>::setLargeItem(const ItemType& anItem)
{
	largeItem = anItem;
}

template <class ItemType>
auto TriNode<ItemType>::getLeftChildPtr() const
{
	return leftChildPtr;
}

template <class ItemType>
auto TriNode<ItemType>::getMidChildPtr() const
{
	return midChildPtr;
}

template <class ItemType>
auto TriNode<ItemType>::getRightChildPtr() const
{
	return rightChildPtr;
}

template <class ItemType>
void TriNode<ItemType>::setLeftChildPtr(triNodePtr leftPtr)
{
	leftChildPtr = leftPtr;
}

template <class ItemType>
void TriNode<ItemType>::setMidChildPtr(triNodePtr midPtr)
{
	midChildPtr = midPtr;
}

template <class ItemType>
void TriNode<ItemType>::setRightChildPtr(triNodePtr rightPtr)
{
	rightChildPtr = rightPtr;
}