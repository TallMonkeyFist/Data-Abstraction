template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem))
{
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree)
{
	rootPtr = BinaryNodeTree<ItemType>::copyTree(tree.rootPtr);
}

template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
	clear();
}

template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
	return rootPtr == nullptr;
}

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
	return BinaryNodeTree<ItemType>::getHeightHelper(rootPtr);
}

template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
	return BinaryNodeTree<ItemType>::getNumberOfNodes(rootPtr);
}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(PreconViolatedExcept)
{
	if (rootPtr == nullptr)
	{
		throw PreconViolatedExcept("getRootData() called on an empty tree\n");
	}
	return rootPtr->getItem();
}

template <class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData)
{
	if (rootPtr == nullptr)
	{
		rootPtr = std::make_shared<BinaryNode<ItemType>>();
	}
	rootPtr->setItem(newData);
}

template <class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{
	std::shared_ptr<BinaryNode<ItemType>> newNodePtr = std::make_shared<BinaryNode<ItemType>>(newEntry, nullptr, nullptr);
	rootPtr = placeNode(rootPtr, newNodePtr);

	return true;
}

template <class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target)
{
	bool removed = false;
	rootPtr = removeValue(rootPtr, target, removed);
	return removed;
}

template <class ItemType>
void BinarySearchTree<ItemType>::clear()
{
	rootPtr = nullptr;
}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& target) const throw(NotFoundException)
{
	auto nodePtr = findNode(rootPtr, target);
	if (nodePtr == nullptr)
	{
		throw NotFoundException("getEntry() called when entry was not in the tree");
	}
	return nodePtr->getItem();
}

template <class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& target) const
{
	return findNode(rootPtr, target) != nullptr;
}

template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
	BinaryNodeTree<ItemType>::preorderTraverse(visit, rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
	BinaryNodeTree<ItemType>::inorderTraverse(visit, rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
	BinaryNodeTree<ItemType>::postorderTraverse(visit, rootPtr);
}

template <class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& rightHandSide)
{
	if (this != &rightHandSide)
	{
		this->clear();
		this->rootPtr = BinaryNodeTree<ItemType>::copyTree(rightHandSide.rootPtr);
	}
	return *this;
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
	if(subTreePtr == nullptr)
	{
		return newNodePtr;
	}

	if (subTreePtr->getItem() > newNodePtr->getItem())
	{
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	else
	{
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	return subTreePtr;
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType& target, bool& isSuccessful)
{
	if (subTreePtr == nullptr)
	{
		isSuccessful = false;
		return subTreePtr;
	}
	if (subTreePtr->getItem() == target)
	{
		subTreePtr = removeNode(subTreePtr);
		isSuccessful = true;
		return subTreePtr;
	}
	if (subTreePtr->getItem() > target)
	{
		auto tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	else
	{
		auto tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	return subTreePtr;
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr)
{
	if (nodePtr == nullptr || (nodePtr->getLeftChildPtr() == nullptr && nodePtr->getRightChildPtr() == nullptr))
	{
		return nullptr;
	}
	if (nodePtr->getLeftChildPtr() != nullptr && nodePtr->getRightChildPtr() == nullptr)
	{
		return nodePtr->getLeftChildPtr();
	}
	if (nodePtr->getLeftChildPtr() == nullptr && nodePtr->getRightChildPtr() != nullptr)
	{
		return nodePtr->getRightChildPtr();
	}
	ItemType newNodeValue;
	auto tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
	nodePtr->setRightChildPtr(tempPtr);
	nodePtr->setItem(newNodeValue);
	return nodePtr;
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, ItemType& newNodeValue)
{
	if (subTreePtr->getLeftChildPtr() == nullptr)
	{
		newNodeValue = subTreePtr->getItem();
		return removeNode(subTreePtr);
	}
	auto tempPtr = removeLeftmostNode(subTreePtr->getLeftChildPtr(), newNodeValue);
	subTreePtr->setLeftChildPtr(tempPtr);
	return subTreePtr;
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType& target) const
{
	if (subTreePtr == nullptr || subTreePtr->getItem() == target)
	{
		return subTreePtr;
	}
	if (subTreePtr->getItem() > target)
	{
		return findNode(subTreePtr->getLeftChildPtr(), target);
	}
	return findNode(subTreePtr->getRightChildPtr(), target);
}