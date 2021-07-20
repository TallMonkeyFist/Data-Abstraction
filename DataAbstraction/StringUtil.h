#pragma once
#include <string>
#include <iostream>


static void printBackwards(std::string s, int n)
{
	if (n == 0) { return; }

	std::cout << s[n - 1];
	printBackwards(s, n - 1);
}

static void writeArrayBackwards(const char anArray[], int start, int end)
{
	if (start <= end)
	{
		std::cout << anArray[end];
		writeArrayBackwards(anArray, start, end - 1);
	}
}

static bool validCIdentifier(std::string s, int n)
{
	if (n == 0)
	{
		return isalpha(s[0]);
	}
	if (isalpha(s[n]) || isdigit(s[n]))
	{
		return validCIdentifier(s, n - 1);
	}
	return false;
}

static bool validCIdentifier(std::string s)
{
	return validCIdentifier(s, s.length() - 1);
}

static bool isPalindrome(std::string s, int start, int end)
{
	if (start >= end)
	{
		return true;
	}
	if (s[start] == s[end])
	{
		return isPalindrome(s, start + 1, end - 1);
	}
	return false;
}

static bool isPalindrome(std::string s)
{
	if (s.length() <= 1)
	{
		return true;
	}
	return isPalindrome(s, 0, s.length() - 1);
}

static bool isAB(std::string s, int start, int end)
{
	if (start > end)
	{
		return true;
	}
	if (toupper(s[start]) == 'A' && toupper(s[end]) == 'B')
	{
		return isAB(s, start + 1, end - 1);
	}
	return false;
}

static bool isAB(std::string s)
{
	if (s.length() <= 0)
	{
		return true;
	}
	return isAB(s, 0, s.length() - 1);
}