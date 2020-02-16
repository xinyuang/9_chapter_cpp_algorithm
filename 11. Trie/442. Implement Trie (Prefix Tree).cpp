//442. Implement Trie(Prefix Tree)
//
//1. when add, no mater new Node or not, cur = cur->next[w[i] - 'a']
//2. when search, cur = cur->next[w[i] - 'a']

class TrieNode {
public:
	TrieNode* next[26];
	bool isWord;
	TrieNode()
	{
		for (int i = 0; i < 26; i++)
		{
			next[i] = nullptr;
		}
		isWord = false;
	}
};

class Trie {
private:
	TrieNode* root;
public:
	Trie() {
		root = new TrieNode();
	}

	/*
	 * @param word: a word
	 * @return: nothing
	 */
	void insert(string& word) {
		// write your code here
		TrieNode* cur = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (!cur->next[word[i] - 'a']) cur->next[word[i] - 'a'] = new TrieNode();
			cur = cur->next[word[i] - 'a'];
		}

		cur->isWord = true;
	}

	/*
	 * @param word: A string
	 * @return: if the word is in the trie.
	 */
	bool search(string& word) {
		// write your code here
		TrieNode* cur = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (!cur->next[word[i] - 'a']) return false;
			cur = cur->next[word[i] - 'a'];
		}
		return cur->isWord;
	}

	/*
	 * @param prefix: A string
	 * @return: if there is any word in the trie that starts with the given prefix.
	 */
	bool startsWith(string& prefix) {
		// write your code here
		TrieNode* cur = root;
		for (int i = 0; i < prefix.size(); i++)
		{
			if (!cur->next[prefix[i] - 'a']) return false;
			cur = cur->next[prefix[i] - 'a'];
		}
		return true;
	}
};