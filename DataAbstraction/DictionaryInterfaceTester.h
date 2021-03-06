#pragma once

#include "ArrayDictionary.h"
#include "TreeDictionary.h"
#include "HashedDictionary.h"
#include "SortedLinkedDictionary.h"
#include "LinkedSortedDictionary.h"
#include <iostream>

class DictionaryInterfaceTester
{
private:

	static void printValue(std::string& value)
	{
		std::cout << value + " ";
	}

	static void printEntry(Entry<int, std::string>& entry)
	{
		std::cout << entry.getValue() << '\n';
	}

	static void dictionaryTester(DictionaryInterface<int, std::string>* dictPtr, char type)
	{
		DictionaryInterface<int, std::string>* copyPtr = nullptr;

		std::string data[] = { "one", "two", "three", "four", "five", "six" };

		std::cout << "isEmpty(): returns " << dictPtr->isEmpty()
			<< "; should be 1 (true)\n";
		std::cout << "getNumberOfEntries(): returns " <<
			dictPtr->getNumberOfEntries() << "; should be 0\n";

		for (int i = 0; i < 6; i++)
		{
			if (dictPtr->add(i, data[i]))
			{
				try
				{
					std::cout << "Inserted " << dictPtr->getValue(i) <<
						" with key " << i << "\n";
				}
				catch (std::logic_error except)
				{
					std::cout << "Failed to get entry with key "
						<< i << "\n";
				}
			}
			else
			{
				std::cout << "Failed to insert " << data[i] << " with key "
					<< i << '\n';
			}
		}

		std::cout << "Printing all values\n\n";
		dictPtr->traverse(printValue);
		std::cout << "\n\n";

		std::cout << "replace(0, \"zero\"): returns " << dictPtr->replace(0, "zero")
			<< "; should be 1 (true)\n";
		std::cout << "getValue(0): returns " << dictPtr->getValue(0)
			<< "; should be zero\n";
		std::cout << "replace(5, \"seven\"): returns " << dictPtr->replace(5, "seven")
			<< "; should be 1 (true)\n";
		std::cout << "getValue(5): returns " << dictPtr->getValue(5)
			<< "; should be seven\n";
		std::cout << "replace(6, \"eight\"): returns " << dictPtr->replace(6, "eight")
			<< "; should be 0 (false)\n";
		std::cout << "getValue(6): should throw exception\n";
		try
		{
			std::cout << "getValue(6): returns " << dictPtr->getValue(6)
				<< "; should throw exception\n";
		}
		catch(std::logic_error)
		{
			std::cout << "getValue(6): throws an exception\n";
		}

		std::cout << "\nCopying dictionary\n";
		if (toupper(type) == 'A')
		{
			copyPtr = new ArrayDictionary<int, std::string>(*(ArrayDictionary<int, std::string>*)dictPtr);
		}
		else if (toupper(type) == 'H')
		{
			copyPtr = new HashedDictionary<int, std::string>(*(HashedDictionary<int, std::string>*)dictPtr);
		}
		else if (toupper(type) == 'L')
		{
			copyPtr = new SortedLinkedDictionary<int, std::string>(*(SortedLinkedDictionary<int, std::string>*)dictPtr);
		}
		else if (toupper(type) == 'B')
		{
			copyPtr = new LinkedSortedDictionary<int, std::string>(*(LinkedSortedDictionary<int, std::string>*)dictPtr);
		}
		else
		{
			copyPtr = new TreeDictionary<int, std::string>(*(TreeDictionary<int, std::string>*)dictPtr);
		}

		std::cout << "\nPrinting dictPtr\n";
		dictPtr->traverse(printValue);

		std::cout << "\n\nPrinting copyPtr\n";
		copyPtr->traverse(printValue);

		std::cout << "\n\ncontains(0): returns " << dictPtr->contains(0)
			<< "; should be 1 (true)\n";
		std::cout << "remove(0): returns " << dictPtr->remove(0)
			<< "; should be 1 (true)\n";
		std::cout << "contains(0): returns " << dictPtr->contains(0)
			<< "; should be 0 (false)\n";
		std::cout << "copyPtr->contains(0): returns " << copyPtr->contains(0)
			<< "; should be 1 (true)\n";

		std::cout << "getNumberOfEntries(): returns " << dictPtr->getNumberOfEntries()
			<< "; should be 5\n";
		std::cout << "isEmpty(): returns " << dictPtr->isEmpty()
			<< "; should be 0 (false)\n";
		std::cout << "clearing dictPtr\n";
		dictPtr->clear();
		std::cout << "getNumberOfEntries(): returns " << dictPtr->getNumberOfEntries()
			<< "; should be 0\n";
		std::cout << "copyPtr->getNumberOfEntries(): returns " << copyPtr->getNumberOfEntries()
			<< "; should be 6\n";


		delete copyPtr;
		copyPtr = nullptr;
	}

public:
	static void TestDictionary()
	{
		DictionaryInterface<int, std::string>* dictionaryPtr = nullptr;
		char userChoice;
		std::cout << "Enter 'A' to test the array-based implementation\n";
		std::cout << "Enter 'H' to test the hashed-based implementation\n";
		std::cout << "Enter 'L' to test the sorted-linked list implementation\n";
		std::cout << "Enter 'B' to test the sorted-linked implementation\n";
		std::cout << "Enter 'T' to test the tree-based implementation\n";
		std::cin >> userChoice;

		if (toupper(userChoice) == 'A')
		{
			dictionaryPtr = new ArrayDictionary<int, std::string>();
			std::cout << "Testing the array-based dictionary\n\n";

			dictionaryTester(dictionaryPtr, userChoice);
		}
		else if (toupper(userChoice) == 'H')
		{
			dictionaryPtr = new HashedDictionary<int, std::string>();
			std::cout << "Testing the hashed-based dictionary\n\n";

			dictionaryTester(dictionaryPtr, userChoice);
		}
		else if (toupper(userChoice) == 'L')
		{
			dictionaryPtr = new SortedLinkedDictionary<int, std::string>();
			std::cout << "Testing the sorted-linked list dictionary\n\n";

			dictionaryTester(dictionaryPtr, userChoice);
		}
		else if (toupper(userChoice) == 'B')
		{
			dictionaryPtr = new LinkedSortedDictionary<int, std::string>();
			std::cout << "Testing the sorted-linked dictionary\n\n";

			dictionaryTester(dictionaryPtr, userChoice);
		}
		else if(toupper(userChoice) == 'T')
		{
			dictionaryPtr = new TreeDictionary<int, std::string>();
			std::cout << "Testing the tree-based dictionary\n\n";

			dictionaryTester(dictionaryPtr, userChoice);
		}

		delete dictionaryPtr;
		dictionaryPtr = nullptr;
	}
};