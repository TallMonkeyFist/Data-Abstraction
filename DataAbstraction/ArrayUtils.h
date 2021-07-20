#pragma once

#include "Math.h"
#include <iostream>

template <class ItemType>
void printArray(const ItemType theArray[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << theArray[i] << " ";
	}
	std::cout << "\n";
}

template <class ItemType>
int binarySearch(const ItemType anArray[], int first, int last, ItemType target)
{
	if (first > last)
	{
		return -1;
	}

	int mid = first + (last - first) / 2;

	if (target == anArray[mid])
	{
		return mid;
	}
	if (anArray[mid] < target)
	{
		return binarySearch(anArray, mid + 1, last, target);
	}
	return binarySearch(anArray, first, mid - 1, target);
}

template <class ItemType>
ItemType maxArray(const ItemType anArry[], int first, int last)
{
	if (first == last)
	{
		return anArry[first];
	}

	int mid = first + (last - first) / 2;

	return max(maxArray(anArry, first, mid), maxArray(anArry, mid + 1, last));
}

template <class ItemType>
ItemType minArray(const ItemType anArry[], int first, int last)
{
	if (first == last)
	{
		return anArry[first];
	}

	int mid = first + (last - first) / 2;

	return min(minArray(anArry, first, mid), minArray(anArry, mid + 1, last));
}

template <class ItemType>
ItemType sum(const ItemType anArray[], int first, int last)
{
	if (last == first)
	{
		return anArray[first];
	}
	return anArray[last] + sum(anArray, first, last - 1);
}