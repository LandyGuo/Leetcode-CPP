/*
208. Implement Trie (Prefix Tree)   
Difficulty: Medium
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
/*2nd pass
注意前缀树的实现最好用map结构来保存孩子，否则每次查找需要遍历一遍孩子
*/


class TrieNode {
public:
	// Initialize your data structure here.
	char c;
	TrieNode* children[26];
	bool isWord;
	TrieNode(char chr = 0) {
		c = chr;
		memset(children, 0x0, sizeof(TrieNode*)* 26);
		isWord = false;
	}

};

class Trie {
public:
	Trie() {
		root = new TrieNode();

	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* curNode = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (curNode->children[word[i] - 'a'] == NULL)
				curNode->children[word[i] - 'a'] = new TrieNode(word[i]);
			curNode = curNode->children[word[i] - 'a'];
			if (i == word.size() - 1)
				curNode->isWord = true;
		}
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* curNode = root;
		for (char c : word)
		{
			if (curNode->children[c - 'a'] == NULL)
				return false;
			curNode = curNode->children[c - 'a'];
		}
		return curNode->isWord ? true : false;//与查找prefix的区别
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* curNode = root;
		for (char c : prefix)
		{
			if (curNode->children[c - 'a'] == NULL)
				return false;
			curNode = curNode->children[c - 'a'];
		}
		return true;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
