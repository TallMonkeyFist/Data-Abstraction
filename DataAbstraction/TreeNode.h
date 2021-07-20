#pragma once

template <class ItemType>
class TreeNode
{
public:
	TreeNode() : left(-1), right(-1) { }
	TreeNode(const ItemType& nodeItem, int _left, int _right) : item(nodeItem), left(_left), right(_right) { }

	void setItem(const ItemType& newItem) { item = newItem; }
	ItemType getItem() const { return item; }

	void setLeft(int left) { this->left = left; }
	int getLeft() const { return left; }

	void setRight(int right) { this->right = right; }
	int getRight() const { return right; }

private:
	ItemType item;
	int left;
	int right;
};