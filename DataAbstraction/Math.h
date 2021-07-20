#pragma once

static int factorial(const int& n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	return n * factorial(n - 1);
}

static int sumUpTo(const int& n)
{
	if (n <= 0) 
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return n + sumUpTo(n - 1);
}

template <class ItemType>
ItemType max(const ItemType& a, const ItemType& b)
{
	return a > b ? a : b;
}

template <class ItemType>
ItemType min(const ItemType& a, const ItemType& b)
{
	return a > b ? b : a;
}