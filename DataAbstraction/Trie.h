#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <vector>

class Trie
{
public:
	
	Trie();
	~Trie();
	void add(const std::string& word);
	bool contains(const std::string& word) const;
	void clear();

private:
	class TrieNode
	{
	public:
		TrieNode(char c)
		{
			value = c;
			nextNodes = new TrieNode*[256];
			for (int i = 0; i < 256; i++)
			{
				nextNodes[i] = nullptr;
			}
			endNode = false;
		}

		~TrieNode()
		{
			for (int i = 0; i < 256; i++)
			{
				delete nextNodes[i];
				nextNodes[i] = nullptr;
			}
			delete[] nextNodes;
			nextNodes = nullptr;
		}

		bool add(const std::string& word)
		{
			if (word.length() < 1)
			{
				return false;
			}
			int nextChar = std::toupper((unsigned char)word[0]);
			if (nextNodes[nextChar] == nullptr)
			{
				nextNodes[nextChar] = new TrieNode(nextChar);
			}
			if (word.length() == 1)
			{
				nextNodes[nextChar]->endNode = true;
				return true;
			}
			return nextNodes[nextChar]->add(word.substr(1, word.length() - 1));
		}

		bool contains(const std::string& word) const
		{
			if (word.length() <= 0)
			{
				return true;
			}
			int nextChar = std::toupper((unsigned char)word[0]);
			if (nextNodes[nextChar] == nullptr)
			{
				return false;
			}
			if (word.length() == 1)
			{
				if (nextNodes[nextChar]->endNode)
				{
					return true;
				}
				return false;
			}

			return nextNodes[nextChar]->contains(word.substr(1, word.length() - 1));
		}

		void clear()
		{
			for (int i = 0; i < 256; i++)
			{
				delete nextNodes[i];
				nextNodes[i] = nullptr;
			}
		}

		unsigned char value;
		bool endNode;
		TrieNode** nextNodes;
	};

	TrieNode* rootNode;
};

