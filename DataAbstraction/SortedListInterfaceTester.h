#pragma once

#include "LinkedSortedList.h"
#include "SortedListHasA.h"
#include "SortedListIsA.h"
#include "SortedListAsA.h"
#include <iostream>

class SortedListInterfaceTester
{
private:

	template <class ItemType>
	static void printList(SortedListInterface<ItemType>* listPtr)
	{
		if (listPtr->getLength() == 0)
		{
			std::cout << "Empty List";
		}
		for (int i = 0; i < listPtr->getLength(); i++)
		{
			std::cout << listPtr->getEntry(i) << " ";
		}
		std::cout << "\n";
	}

	template <class ItemType>
	static void printListClear(SortedListInterface<ItemType>* listPtr)
	{
		std::cout << '\n';
		if (listPtr->getLength() == 0)
		{
			std::cout << "Empty List";
		}
		for (int i = 0; i < listPtr->getLength(); i++)
		{
			std::cout << listPtr->getEntry(i) << " ";
		}
		std::cout << "\n\n";
	}

	template <class ItemType>
	static void printList(LinkedList<ItemType>* listPtr)
	{
		if (listPtr->getLength() == 0)
		{
			std::cout << "Empty List";
		}
		for (int i = 0; i < listPtr->getLength(); i++)
		{
			std::cout << listPtr->getEntry(i) << " ";
		}
		std::cout << "\n";
	}

	template <class ItemType>
	static void printListClear(LinkedList<ItemType>* listPtr)
	{
		std::cout << '\n';
		if (listPtr->getLength() == 0)
		{
			std::cout << "Empty List";
		}
		for (int i = 0; i < listPtr->getLength(); i++)
		{
			std::cout << listPtr->getEntry(i) << " ";
		}
		std::cout << "\n\n";
	}

	static void sortedListTester(SortedListInterface<int>* listPtr, char userChoice)
	{
		int data[] = { 1, 6, 8, INT_MIN, INT_MAX, 7 };

		for (int i = 0; i < 6; i++)
		{
			if (listPtr->insertSorted(data[i]))
			{
				try
				{
					std::cout << "Inserted " << data[i]
						<< " at index " << listPtr->getIndex(data[i]) << '\n';
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

		try
		{
			listPtr->getEntry(4);
		}
		catch (PreconViolatedExcept e)
		{
			std::cout << "Caught expected precondition violated exception\n";
		}
		printListClear(listPtr);

		SortedListInterface<int>* copyPtr = nullptr;

		std::cout << "Copying listPtr to copyPtr\n";
		if (toupper(userChoice) == 'H')
		{
			copyPtr = new SortedListHasA<int>(*((SortedListHasA<int>*)listPtr));
		}
		else if (toupper(userChoice) == 'A')
		{
			copyPtr = new SortedListAsA<int>(*((SortedListAsA<int>*)listPtr));
		}
		else
		{
			copyPtr = new LinkedSortedList<int>(*((LinkedSortedList<int>*)listPtr));
		}
		std::cout << "\nPrinting listPtr\n";
		printListClear(listPtr);
		std::cout << "Printing copyPtr\n";
		printListClear(copyPtr);
		
		std::cout << "copyPtr->removeSorted(6): returns " << copyPtr->removeSorted(6) 
			<< "; should be 1 (true)\n";
		printListClear(copyPtr); 
		std::cout << "copyPtr->remove(0): returns " << copyPtr->remove(0)
			<< "; should be 1 (true)\n"; 
		std::cout << "copyPtr->remove(copyPtr->getLength() - 1): returns " << copyPtr->remove(copyPtr->getLength() - 1)
			<< "; should be 1 (true)\n";
		printListClear(copyPtr);

		std::cout << "Clearing copyPtr\n";
		copyPtr->clear();
		printListClear(copyPtr);

		try
		{
			listPtr->getEntry(0);
		}
		catch (PreconViolatedExcept e)
		{
			std::cout << "Caught expected precondition violated exception\n";
		}

		delete copyPtr;
		copyPtr = nullptr;
	}

	static void sortedListIsATester(SortedListIsA<int>* listPtr, char userChoice)
	{
		int data[] = { 1, 6, 8, INT_MIN, INT_MAX, 7 };

		for (int i = 0; i < 6; i++)
		{
			if (listPtr->insertSorted(data[i]))
			{
				try
				{
					std::cout << "Inserted " << data[i]
						<< " at index " << listPtr->getIndex(data[i]) << '\n';
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

		try
		{
			listPtr->getEntry(4);
		}
		catch (PreconViolatedExcept e)
		{
			std::cout << "Caught expected precondition violated exception\n";
		}
		printListClear(listPtr);

		std::cout << "Copying listPtr to copyPtr\n";
		SortedListIsA<int>* copyPtr = new SortedListIsA<int>(*((SortedListIsA<int>*)listPtr));

		std::cout << "\nPrinting listPtr\n";
		printListClear(listPtr);
		std::cout << "Printing copyPtr\n";
		printListClear(copyPtr);

		std::cout << "copyPtr->removeSorted(6): returns " << copyPtr->removeSorted(6)
			<< "; should be 1 (true)\n";
		printListClear(copyPtr);
		std::cout << "copyPtr->remove(0): returns " << copyPtr->remove(0)
			<< "; should be 1 (true)\n";
		std::cout << "copyPtr->remove(copyPtr->getLength() - 1): returns " << copyPtr->remove(copyPtr->getLength() - 1)
			<< "; should be 1 (true)\n";
		std::cout << "copyPtr->replace(1, 5): returns " << copyPtr->replace(1, 5)
			<< "; should be 0 (false)\n";
		std::cout << "copyPtr->insert(1, 5): returns " << copyPtr->insert(1, 5)
			<< "; should be 0 (false)\n";
		printListClear(copyPtr);

		std::cout << "Clearing copyPtr\n";
		copyPtr->clear();
		printListClear(copyPtr);

		try
		{
			listPtr->getEntry(0);
		}
		catch (PreconViolatedExcept e)
		{
			std::cout << "Caught expected precondition violated exception\n";
		}

		delete copyPtr;
		copyPtr = nullptr;
	}
public:
	static void TestSortedListInterfaceDriver()
	{
		SortedListInterface<int>* listPtr = nullptr;
		char userChoice;
		std::cout << "Enter 'H' to test the linked-based Has-A implementation\n";
		std::cout << "Enter 'I' to test the linked-based Is-A implementation\n";
		std::cout << "Enter 'A' to test the linked-based As-A implementation\n";
		std::cout << "Enter 'L' to test the linked-based implementation\n";
		std::cin >> userChoice;

		if (toupper(userChoice) == 'H')
		{
			listPtr = new SortedListHasA<int>();
			std::cout << "Testing the linked-based Has-A list\n\n";

			std::cout << "The initial list is empty\n";
			sortedListTester(listPtr, userChoice);

			delete listPtr;
			listPtr = nullptr;
		}
		else if (toupper(userChoice) == 'A')
		{
			listPtr = new SortedListAsA<int>();
			std::cout << "Testing the linked-based As-A list\n\n";

			std::cout << "The initial list is empty\n";
			sortedListTester(listPtr, userChoice);

			delete listPtr;
			listPtr = nullptr;
		}
		else if (toupper(userChoice) == 'I')
		{
			SortedListIsA<int>* listPtr2 = new SortedListIsA<int>();
			std::cout << "Testing the linked-based Is-A list\n\n";

			std::cout << "The initial list is empty\n";
			sortedListIsATester(listPtr2, userChoice);

			delete listPtr2;
			listPtr2 = nullptr;
		}
		else
		{
			listPtr = new LinkedSortedList<int>();
			std::cout << "Testing the linked-based list\n\n";

			std::cout << "The initial list is empty\n";
			sortedListTester(listPtr, userChoice);

			delete listPtr;
			listPtr = nullptr;
		}
		std::cout << "All done!\n";
	}
};