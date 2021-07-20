#pragma once

#include "BinaryNodeTree.h"

template <class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType>
{
public:
	BinarySearchTree();
	BinarySearchTree(const ItemType& rootItem);
	BinarySearchTree(const BinarySearchTree& tree);
	virtual ~BinarySearchTree();

	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const throw(PreconViolatedExcept);
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& target);
	void clear();
	ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException);
	bool contains(const ItemType& anEntry);

	void preorderTraverse(void visit(ItemType&)) const;
	void inorderTraverse(void visit(ItemType&)) const;
	void postorderTraverse(void visit(ItemType&)) const;

	BinarySearchTree<ItemType>& operator=(const BinarySearchTree<ItemType>& rightHandSide);
protected:
	std::shared_ptr<BinaryNode<ItemType>> placeNode(
		std::shared_ptr<BinaryNode<ItemType>> subTreePtr, 
		std::shared_ptr<BinaryNode<ItemType>> newNodePtr);

	std::shared_ptr<BinaryNode<ItemType>> removeValue(
		std::shared_ptr<BinaryNode<ItemType>> subTreePtr, 
		const ItemType& target, bool& isSuccessful) override;

	std::shared_ptr<BinaryNode<ItemType>> removeNode(
		std::shared_ptr<BinaryNode<ItemType>> nodePtr);

	std::shared_ptr<BinaryNode<ItemType>> removeLeftmostNode(
		std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
		ItemType& inorderSuccessor);

	std::shared_ptr<BinaryNode<ItemType>> findNode(
		std::shared_ptr<BinaryNode<ItemType>> treePtr, 
		const ItemType& target) const;
private:
	std::shared_ptr<BinaryNode<ItemType>> rootPtr;
};

#include "BinarySearchTree.cpp"