//559. Trie Service
//
//1. build trie{ unordered_map<char,TrieNode*> children, vector<int> top10 }
//2. every time add new word, use insertion sort to update top10 frequency
//3. for insertion, start ptr = cur->top10.size() - 1;

/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 *     vector<int> top10;
 * };
 */
class TrieService {
	private:
		TrieNode* root;

	public:
		TrieService() {
			root = new TrieNode();
		}

		TrieNode* getRoot() {
			// Return root of trie root, and 
			// lintcode will print the tree struct.
			return root;
		}

		void insert(string& word, int frequency) {
			// Write your code here
			TrieNode* cur = getRoot();
			for (int i = 0; i < word.size(); i++)
			{
				if (cur->children.find(word[i]) == cur->children.end())
				{
					TrieNode* newNode = new TrieNode();
					cur->children[word[i]] = newNode;
				}
				cur = cur->children[word[i]];
				addFreq(cur, frequency);
			}
		}

		void addFreq(TrieNode* cur, int frequency)
		{
			int ptr = cur->top10.size() - 1;
			cur->top10.push_back(frequency);
			while (ptr >= 0 && cur->top10[ptr] < frequency)
			{
				cur->top10[ptr + 1] = cur->top10[ptr];
				ptr--;
			}
			cur->top10[ptr + 1] = frequency;
			if (cur->top10.size() > 10) cur->top10.pop_back();
		}
};

