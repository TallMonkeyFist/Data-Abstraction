#pragma once

#include "BinarySearchTree.h"
#include <iostream>

class BinarySearchTreeTester
{
private:

	static void printNode(int& item)
	{
		std::cout << item << " ";
	}
public:
	static void BSTTestDriver()
	{
		std::cout << "Testing the Binary Search Tree\n\n==============================\n\n";

		BinarySearchTree<int>* bst = new BinarySearchTree<int>();

		std::cout << "Initial tree is empty\n";
		std::cout << "isEmpty(): returns " << bst->isEmpty() << "; should be 1 (true)\n";

		int data[] = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};

		for (int i = 0; i < 10; i++)
		{
			if (bst->add(data[i]))
			{
				try
				{
					std::cout << "Inserted " << bst->getEntry(data[i])
						<< " into the Binary Search Tree\n";
				}
				catch (std::logic_error except)
				{
					std::cout << "Failed to get entry " << data[i]
						<< " from the Binary Search Tree after insertion\n";
				}
			}
			else
			{
				std::cout << "Can not insert " << data[i] << " into the Binary Search Tree\n";
			}
		}

		std::cout << "\nInorder traversal\n\n";
		bst->inorderTraverse(printNode);
		std::cout << "Printed Values\n0 1 2 3 4 5 6 7 8 9 Expected Values\n\n";

		std::cout << "Preorder traversal\n\n";
		bst->preorderTraverse(printNode);
		std::cout << "Printed Values\n1 0 3 2 5 4 7 6 9 8 Expected Values\n\n";

		std::cout << "Postorder traversal\n\n";
		bst->postorderTraverse(printNode);
		std::cout << "Printed Values\n0 2 4 6 8 9 7 5 3 1 Expected Values\n\n";

		std::cout << "getHeight(): returns " << bst->getHeight() << "; should be 6\n";

		std::cout << "getRootData(): returns " << bst->getRootData() << "; should be 1\n";

		std::cout << "remove(1): returns " << bst->remove(1) << "; should be 1 (true)\n";
		std::cout << "remove(4): returns " << bst->remove(4) << "; should be 1 (true)\n";
		std::cout << "remove(9): returns " << bst->remove(9) << "; should be 1 (true)\n";

		std::cout << "\n";
		bst->inorderTraverse(printNode);
		std::cout << "Printed Values\n0 2 3 5 6 7 8 Expected Values\n\n";

		std::cout << "\n==============================\n\nAll done testing!\n";

		delete bst;
		bst = nullptr;
	}
};