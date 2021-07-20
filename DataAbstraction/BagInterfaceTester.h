#pragma once
#include <string>
#include <iostream>
#include "BagInterface.h"
#include "ArrayBag.h"
#include "LinkedBag.h"

class BagInterfaceTester
{
private:
	static void displayBag(BagInterface<std::string>* bagPtr)
	{
		std::cout << "The bag contains " << bagPtr->getCurrentSize()
			<< " items:\n";
		std::vector<std::string> bagItems = bagPtr->toVector();
		int numberOfEntries = bagPtr->getCurrentSize();
		for (int i = 0; i < numberOfEntries; i++)
		{
			std::cout << bagItems[i] << " ";
		}
		std::cout << "\n\n";
	}

	static void bagTester(BagInterface<std::string>* bagPtr)
	{
		std::cout << "isEmpty: returns " << bagPtr->isEmpty()
			<< "; should be 1 (true)\n";
		std::string items[] = { "one", "two", "three", "four", "five", "one" };
		std::cout << "Add 6 items to the bag: \n";
		for (int i = 0; i < 6; i++)
		{
			bagPtr->add(items[i]);
		}
		displayBag(bagPtr);
		std::cout << "isEmpty: returns " << bagPtr->isEmpty()
			<< "; should be 0 (false)\n";
		std::cout << "getCurrentSize returns: " << bagPtr->getCurrentSize()
			<< "; should be 6\n";
		std::cout << "Try to add another entry: add(\"extra\") returns "
			<< bagPtr->add("extra") << "; should be 1 (true)\n";
		std::cout << "Try to remove entry: remove(\"one\") returns "
			<< bagPtr->remove("one") << "; should be 1 (true)\n";
		std::cout << "Try to remove another entry: remove(\"one\") returns "
			<< bagPtr->remove("one") << "; should be 1 (true)\n";
		std::cout << "Try to remove another entry: remove(\"one\") returns "
			<< bagPtr->remove("one") << "; should be 0 (false)\n\n";
		displayBag(bagPtr);
		std::cout << "Clearing bag\n";
		bagPtr->clear();
		std::cout << "isEmpty: returns " << bagPtr->isEmpty()
			<< "; should be 1 (true)\n";
		std::cout << "getCurrentSize returns: " << bagPtr->getCurrentSize()
			<< "; should be 0\n\n";
	}

public:
	static void TestBagInterfaceDriver()
	{
		BagInterface<std::string>* bagPtr = nullptr;
		char userChoice;
		std::cout << "Enter 'A' to test the array-based implementation\n";
		std::cout << "Enter 'L' to test the linked-based implementation\n";
		std::cin >> userChoice;

		if (toupper(userChoice) == 'A')
		{
			bagPtr = new ArrayBag<std::string>();
			std::cout << "Testing the Array-Based bag\n\n";
		}
		else
		{
			bagPtr = new LinkedBag<std::string>();
			std::cout << "Testing the Array-Based bag\n\n";
		}

		std::cout << "The initial bag is empty\n";
		bagTester(bagPtr);
		delete bagPtr;
		bagPtr = nullptr;
		std::cout << "All done!\n";
	}
};