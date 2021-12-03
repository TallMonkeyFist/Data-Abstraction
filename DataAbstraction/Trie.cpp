#include "Trie.h"

Trie::Trie() : rootNode(new TrieNode(' '))
{
}

Trie::~Trie()
{
	clear();
}

void Trie::add(const std::string& word)
{
	rootNode->add(word);
}

bool Trie::contains(const std::string& word) const
{
	return rootNode->contains(word);
}

void Trie::clear()
{
	delete rootNode;
	rootNode = nullptr;
}
