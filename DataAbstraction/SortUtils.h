#pragma once

#include <array>

template <class ItemType>
int findIndexOfLargest(const ItemType theArray[], int size)
{
	int largestIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (theArray[i] > theArray[largestIndex])
		{
			largestIndex = i;
		}
	}

	return largestIndex;
}

template <class ItemType>
int findIndexOfLargest(const ItemType theArray[], int start, int end)
{
	int largestIndex = start;
	for (int i = start + 1; i < end; i++)
	{
		if (theArray[i] > theArray[largestIndex])
		{
			largestIndex = i;
		}
	}

	return largestIndex;
}

template <class ItemType>
void selectionSort(ItemType theArray[], int n)
{
	for (int i = n - 1; i >= 1; i--)
	{
		int index = findIndexOfLargest(theArray, 0, i + 1);
		std::swap(theArray[index], theArray[i]);
	}
}

template <class ItemType>
void bubbleSort(ItemType theArray[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (theArray[j] > theArray[j + 1])
			{
				std::swap(theArray[j], theArray[j + 1]);
			}
		}
	}
}

template <class ItemType>
void insertionSort(ItemType theArray[], int first, int last)
{
	for (int i = first; i < last + 1; i++)
	{
		int temp = theArray[i];
		int index = i;
		while (index > 0 && temp < theArray[index - 1])
		{
			theArray[index] = theArray[index - 1];
			index--;
		}
		theArray[index] = temp;
	}
}

template <class ItemType>
void insertionSort(ItemType theArray[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = theArray[i];
		int index = i;
		while (index > 0 && temp < theArray[index - 1])
		{
			theArray[index] = theArray[index - 1];
			index--;
		}
		theArray[index] = temp;
	}
}

template<class ItemType>
void merge(ItemType theArray[], int first, int mid, int last)
{
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;
	int count = last - first + 1;

	ItemType* tempArray = new ItemType[count];
	int tempIndex = 0;

	while (first1 <= last1 && first2 <= last2)
	{
		if (theArray[first1] <= theArray[first2])
		{
			tempArray[tempIndex++] = theArray[first1++];
		}
		else
		{
			tempArray[tempIndex++] = theArray[first2++];
		}
	}
	while (first1 <= last1)
	{
		tempArray[tempIndex++] = theArray[first1++];
	}
	while (first2 <= last2)
	{
		tempArray[tempIndex++] = theArray[first2++];
	}

	tempIndex = 0;

	for (int i = first; i <= last; i++)
	{
		theArray[i] = tempArray[tempIndex++];
	}

	delete[] tempArray;
	tempArray = nullptr;
}

template<class ItemType>
void mergeSort(ItemType theArray[], int first, int last)
{
	if (first >= last)
	{
		return;
	}
	int mid = first + (last - first) / 2;

	mergeSort(theArray, first, mid);
	mergeSort(theArray, mid + 1, last);
	merge(theArray, first, mid, last);
}

template <class ItemType>
void mergeSort(ItemType theArray[], int n)
{
	mergeSort(theArray, 0, n - 1);
}

template <class ItemType>
void sortFirstMidLast(ItemType theArray[], int first, int mid, int last)
{
	if (theArray[first] > theArray[mid])
	{
		std::swap(theArray[first], theArray[mid]);
	}
	if (theArray[mid] > theArray[last])
	{
		std::swap(theArray[mid], theArray[last]);
	}
	if (theArray[first] > theArray[mid])
	{
		std::swap(theArray[first], theArray[mid]);
	}
	std::swap(theArray[mid], theArray[last - 1]);
}

template <class ItemType>
int partition(ItemType theArray[], int first, int last)
{
	int mid = first + (last - first) / 2;

	sortFirstMidLast(theArray, first, mid, last);

	int pivotIndex = last - 1;
	ItemType pivot = theArray[pivotIndex];

	int indexFromLeft = first + 1;
	int indexFromRight = last - 2;

	bool finished = false;
	while (!finished)
	{
		while (theArray[indexFromLeft] < pivot)
		{
			indexFromLeft++;
		}
		while (theArray[indexFromRight] > pivot)
		{
			indexFromRight--;
		}
		if (indexFromLeft < indexFromRight)
		{
			std::swap(theArray[indexFromLeft++], theArray[indexFromRight--]);
		}
		else
		{
			finished = true;
		}
	}

	std::swap(theArray[pivotIndex], theArray[indexFromLeft]);
	pivotIndex = indexFromLeft;

	return pivotIndex;
}

template <class ItemType>
void quickSort(ItemType theArray[], int first, int last)
{
	if (last - first + 1 < 4)
	{
		insertionSort(theArray, first, last);
		return;
	}

	int pivot = partition(theArray, first, last);
	quickSort(theArray, first, pivot);
	quickSort(theArray, pivot + 1, last);
}

template <class ItemType>
void quickSort(ItemType theArray[], int n)
{
	quickSort(theArray, 0, n - 1);
}