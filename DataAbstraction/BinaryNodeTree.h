#pragma once

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PreconViolatedExcept.h"
#include "NotFoundException.h"
#include <memory>

template <class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
public:
	BinaryNodeTree();
	BinaryNodeTree(const ItemType& rootItem);
	BinaryNodeTree(const ItemType& rootItem, const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr, const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
	BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr);
	virtual ~BinaryNodeTree();

	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const throw(PreconViolatedExcept);
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newData);
	bool remove(const ItemType& target);
	void clear();
	ItemType getEntry(const ItemType& target) const throw(NotFoundException);
	bool contains(const ItemType& target) const;

	void preorderTraverse(void visit(ItemType&)) const;
	void inorderTraverse(void visit(ItemType&)) const;
	void postorderTraverse(void visit(ItemType&)) const;

	BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);

protected:
	int getHeightHelper(const std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
	int getNumberOfNodes(const std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

	std::shared_ptr<BinaryNode<ItemType>> balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr);

	virtual std::shared_ptr<BinaryNode<ItemType>> removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType& target, bool& isSuccessful);

	std::shared_ptr<BinaryNode<ItemType>> moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

	virtual std::shared_ptr<BinaryNode<ItemType>> findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target, bool& isSuccessful) const;

	std::shared_ptr<BinaryNode<ItemType>> copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;

	void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

	void preorderTraverse(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
	void inorderTraverse(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
	void postorderTraverse(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;

private:
	std::shared_ptr<BinaryNode<ItemType>> rootPtr;
};

#include "BinaryNodeTree.cpp"