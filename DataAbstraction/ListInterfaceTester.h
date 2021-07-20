#pragma once

#include <iostream>
#include "ArrayList.h"
#include "LinkedList.h"

class ListInterfaceTester
{
private:

	static void printList(ListInterface<std::string>* listPtr)
	{
		for (int i = 0; i < listPtr->getLength(); i++)
		{
			std::cout << listPtr->getEntry(i) << " ";
		}
		std::cout << "\n";
	}

	static void listTester(ListInterface<std::string>* listPtr, char type)
	{
		ListInterface<std::string>* copyListPtr = nullptr;
		std::string data[] = {"one", "two", "three", "four", "five", "six"};
		std::cout << "isEmpty(): returns " << listPtr->isEmpty() 
			<< "; should be 1 (true)\n";
		for (int i = 0; i < 6; i++)
		{
			if (listPtr->insert(i, data[i]))
			{
				try
				{
					std::cout << "Inserted " << listPtr->getEntry(i)
						<< " at index " << i << '\n';
				}
				catch (std::logic_error except)
				{
					std::cout << "Failed to get entry at index "
						<< i << '\n';
				}
			}
			else
			{
				std::cout << "Can not insert " << data[i] << " at index " << i
					<< '\n';
			}
		}

		std::cout << "\nPrinting listPtr\n";
		printList(listPtr);
		std::cout << "\n";

		std::cout << "replace (0, \"zero\"): returns " <<listPtr->replace(0, "zero")
			<<"; should be \"one\"\n"; 
		std::cout << "getEntry(0): returns " << listPtr->getEntry(0) << "; should be \"zero\"\n";
		std::cout << "replace (5, \"seven\"): returns " << listPtr->replace(5, "seven")
			<< "; should be \"six\"\n";
		std::cout << "getEntry(5): returns " << listPtr->getEntry(5) << "; should be \"seven\"\n";
		std::cout << "replace (3, \"eight\"): returns " << listPtr->replace(3, "eight")
			<< "; should be \"four\"\n";
		std::cout << "getEntry(3): returns " << listPtr->getEntry(3) << "; should be \"eight\"\n";

		std::cout << "Copying listPtr to coptListPtr\n";
		if (toupper(type) == 'A')
		{
			copyListPtr = new ArrayList<std::string>(*((ArrayList<std::string>*)listPtr));

		}
		else
		{
			copyListPtr = new LinkedList<std::string>(*((LinkedList<std::string>*)listPtr));
		}

		std::cout << "\nPrinting listPtr\n";
		printList(listPtr);
		std::cout << "\nPrinting copyListPtr\n";
		printList(copyListPtr);
		std::cout << "\n";

		std::cout << "copyListPtr remove(0): returns " << copyListPtr->remove(0) << "; should be 1 (true)\n";

		std::cout << "\nPrinting listPtr\n";
		printList(listPtr);
		std::cout << "\nPrinting copyListPtr\n";
		printList(copyListPtr);
		std::cout << "\n";

		std::cout << "copyListPtr remove(2): returns " << copyListPtr->remove(2) << "; should be 1 (true)\n";
		std::cout << "copyListPtr remove(3): returns " << copyListPtr->remove(3) << "; should be 1 (true)\n";
		std::cout << "\nPrinting copyListPtr\n";
		printList(copyListPtr);
		std::cout << "\n";

		delete copyListPtr;
		copyListPtr = nullptr;

	}

public:
	static void TestListInterfaceDriver()
	{
		ListInterface<std::string>* listPtr = nullptr;
		char userChoice;
		std::cout << "Enter 'A' to test the array-based implementation\n";
		std::cout << "Enter 'L' to test the linked-based implementation\n";
		std::cin >> userChoice;

		if (toupper(userChoice) == 'A')
		{
			listPtr = new ArrayList<std::string>();
			std::cout << "Testing the Array-Based list\n\n";
		}
		else
		{
			listPtr = new LinkedList<std::string>();
			std::cout << "Testing the Linked-Based list\n\n";
		}

		std::cout << "The initial list is empty\n";
		listTester(listPtr, userChoice);
		delete listPtr;
		listPtr = nullptr;
		std::cout << "All done!\n";
	}
};