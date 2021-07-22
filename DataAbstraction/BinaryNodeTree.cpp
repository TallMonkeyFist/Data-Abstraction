template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{
}

template <class ItemType>
BinaryNodeTree<ItemType>::
BinaryNodeTree(const ItemType& rootItem) 
	: rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{
}

template <class ItemType>
BinaryNodeTree<ItemType>::
BinaryNodeTree(const ItemType& rootItem,
			   const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
			   const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr) 
	: rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, 
		copyTree(leftTreePtr.rootPtr), copyTree(rightTreePtr.rootPtr)))
{
}

template <class ItemType>
BinaryNodeTree<ItemType>::
BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr);
}

template <class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
	destroyTree(rootPtr);
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
	return rootPtr == nullptr;
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
	return getHeightHelper(rootPtr);
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
	return getNumberOfNodes(rootPtr);
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const throw (PreconViolatedExcept)
{
	if (rootPtr == nullptr)
	{
		throw PreconViolatedExcept("getRootData() called on an empty tree\n");
	}
	return rootPtr->getItem();
}

template <class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData)
{
	if (rootPtr == nullptr)
	{
		rootPtr = std::make_shared<BinaryNode<ItemType>>();
	}
	rootPtr->setItem(newData);
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
	std::shared_ptr<BinaryNode<ItemType>> newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData, nullptr, nullptr);
	rootPtr = balancedAdd(rootPtr, newNodePtr);
	return true;
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& target)
{
	bool removed = false;
	removeValue(rootPtr, target, removed);
	return removed;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
	destroyTree(rootPtr);
}


template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& target) const throw(NotFoundException)
{
	bool foundNode = false;
	std::shared_ptr<BinaryNode<ItemType>> nodePtr = findNode(rootPtr, target, foundNode);
	if (!foundNode)
	{
		throw NotFoundException("getEntry() called when entry was not in the tree");
	}
	return nodePtr->getItem();
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& target) const
{
	bool foundNode = false;
	findNode(rootPtr, target, foundNode);
	return foundNode;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
	preorderTraverse(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
	inorderTraverse(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
	postorderTraverse(visit, rootPtr);
}

template <class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree<ItemType>& rightHandSide)
{
	if (this != &rightHandSide)
	{
		this->clear();
		this->rootPtr = copyTree(rightHandSide.rootPtr);
	}
	return *this;
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(const std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
	if (subTreePtr == nullptr)
	{
		return 0;
	}
	return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes(const std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
	if (subTreePtr == nullptr)
	{
		return 0;
	}
	return getNumberOfNodes(subTreePtr->getLeftChildPtr()) + 1 + getNumberOfNodes(subTreePtr->getRightChildPtr());
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
	if (subTreePtr == nullptr)
	{
		return newNodePtr;
	}

	std::shared_ptr<BinaryNode<ItemType>> leftPtr = subTreePtr->getLeftChildPtr();
	std::shared_ptr<BinaryNode<ItemType>> rightPtr = subTreePtr->getRightChildPtr();

	if (getHeightHelper(rightPtr) > getHeightHelper(leftPtr))
	{
		leftPtr = balancedAdd(leftPtr, newNodePtr);
		subTreePtr->setLeftChildPtr(leftPtr);
	}
	else
	{
		rightPtr = balancedAdd(rightPtr, newNodePtr);
		subTreePtr->setRightChildPtr(rightPtr);
	}
	return subTreePtr;
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType& target, bool& isSuccessful)
{
	if (subTreePtr == nullptr)
	{
		isSuccessful = false;
		return subTreePtr;
	}
	if (subTreePtr->getItem() == target)
	{
		isSuccessful = true;
		if (subTreePtr->getLeftChildPtr() != nullptr && subTreePtr->getRightChildPtr() != nullptr)
		{
			auto copyPtr = moveValuesUpTree(subTreePtr);
			subTreePtr->setItem(copyPtr->getItem());
		}
		return subTreePtr;
	}
	
	auto nodePtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
	if (isSuccessful)
	{
		return nodePtr;
	}
	nodePtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
	return nodePtr;
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
	if (subTreePtr->getLeftChildPtr() == nullptr && subTreePtr->getRightChildPtr() == nullptr)
	{
		return subTreePtr;
	}
	if (subTreePtr->getRightChildPtr() == nullptr && subTreePtr->getLeftChildPtr() != nullptr || getHeightHelper(subTreePtr->getLeftChildPtr()) > getHeightHelper(subTreePtr->getRightChildPtr()))
	{
		return moveValuesUpTree(subTreePtr->getLeftChildPtr());
	}
	return moveValuesUpTree(subTreePtr->getRightChildPtr());
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target, bool& isSuccessful) const
{
	if (treePtr == nullptr)
	{
		isSuccessful = false;
		return treePtr;
	}
	if (treePtr->getItem() == target)
	{
		isSuccessful = true;
		return treePtr;
	}
	std::shared_ptr<BinaryNode<ItemType>> nodePtr;
	nodePtr = findNode(treePtr->getLeftChildPtr(), target, isSuccessful);
	if (isSuccessful)
	{
		return nodePtr;
	}

	nodePtr = findNode(treePtr->getRightChildPtr(), target, isSuccessful);
	return nodePtr;
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{
	std::shared_ptr<BinaryNode<ItemType>> newNodePtr = nullptr;
	if (oldTreeRootPtr != nullptr)
	{
		newNodePtr = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem());
		newNodePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
		newNodePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
	}
	return newNodePtr;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
	if (subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		subTreePtr.reset();
		subTreePtr = nullptr;
	}
}

template <class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	if (treePtr == nullptr)
	{
		return;
	}
	ItemType theItem = treePtr->getItem();
	visit(theItem);
	preorderTraverse(visit, treePtr->getLeftChildPtr());
	preorderTraverse(visit, treePtr->getRightChildPtr());
}

template <class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	if (treePtr == nullptr)
	{
		return;
	}
	ItemType theItem = treePtr->getItem();
	inorderTraverse(visit, treePtr->getLeftChildPtr());
	visit(theItem);
	inorderTraverse(visit, treePtr->getRightChildPtr());
}

template <class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	if (treePtr == nullptr)
	{
		return;
	}
	ItemType theItem = treePtr->getItem();
	postorderTraverse(visit, treePtr->getLeftChildPtr());
	postorderTraverse(visit, treePtr->getRightChildPtr());
	visit(theItem);
}