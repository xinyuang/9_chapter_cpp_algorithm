//623. K Edit Distance
//1. Trie add all words
//2. dfs trie to get word edit distance < k
//3. init dp(size() + 1, 0), for loop dp[i] = i
//4. new_dp[0] = dp[0] + 1, for (i in range(26)) for j in range(1, dp.size()) word[j] - 'a' == i

class TrieNode {
public:
	TrieNode* next[26];
	bool isWord;
	string Word;
	TrieNode() {
		for (int i = 0; i < 26; i++)
		{
			next[i] = nullptr;
		}
		Word = "";
		isWord = false;
	}
};

class Solution {
private:
	TrieNode* root = new TrieNode();
public:
	/**
	 * @param words: a set of stirngs
	 * @param target: a target string
	 * @param k: An integer
	 * @return: output all the strings that meet the requirements
	 */
	vector<string> kDistance(vector<string>& words, string& target, int k) {
		// write your code here
		for (int i = 0; i < words.size(); i++) addWord(words[i]);
		vector<string> res;
		vector<int> dp(target.size() + 1, 0);
		for (int i = 0; i <= target.size(); i++) dp[i] = i;
		findWords(root, res, dp, target, k);
		return res;
	}

	void findWords(TrieNode* curNode, vector<string>& res, vector<int>& dp, string& target, int k)
	{
		if (curNode->isWord)
		{
			if (dp.back() <= k) {
				res.push_back(curNode->Word);
			}
		}
		for (int i = 0; i < 26; i++)
		{
			if (!curNode->next[i]) continue;
			vector<int> new_dp(target.size() + 1, 0);
			new_dp[0] = dp[0] + 1;
			for (int j = 1; j < new_dp.size(); j++)
			{
				if (target[j - 1] - 'a' == i) new_dp[j] = min(dp[j - 1], min(dp[j] + 1, new_dp[j - 1] + 1));
				else new_dp[j] = min(dp[j - 1], min(dp[j], new_dp[j - 1])) + 1;
			}
			findWords(curNode->next[i], res, new_dp, target, k);
		}

	}

	void addWord(string& word)
	{
		TrieNode* cur = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (!cur->next[word[i] - 'a']) cur->next[word[i] - 'a'] = new TrieNode();
			cur = cur->next[word[i] - 'a'];
		}
		cur->Word = word;
		cur->isWord = true;
	}
};