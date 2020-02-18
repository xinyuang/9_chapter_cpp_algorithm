//634. Word Squares
//1. Trie or Prefix unordered_map to store(prefix, candidate_words)
//2. dfs, res, path, when path.size() == square size, res.push_back(path)
//3. for candidate string in Prefix[prefix] where  prefix = [cur_str[cur_len] for cur_str in path]
//4. backtrack candidate, path.push_back(candidate), dfs, path, pop_back()


class TrieNode {
public:
	TrieNode* next[26];
	vector<string> Words;
	TrieNode() {
		for (int i = 0; i < 26; i++)
		{
			next[i] = nullptr;
		}
		Words = {};
	}
};

class Solution {
private:
	TrieNode* root = new TrieNode();
public:
	/*
	 * @param words: a set of words without duplicates
	 * @return: all word squares
	 */
	vector<vector<string>> wordSquares(vector<string>& words) {
		// write your code here
		if (words.size() == 0) return {};
		for (int i = 0; i < words.size(); i++) {
			root->Words.push_back(words[i]);
			addWord(words[i]);
		}
		vector<vector<string>> res;
		vector<string> path;
		dfs(res, path, words);
		return res;
	}

	void dfs(vector<vector<string>>& res, vector<string>& path, vector<string>& words)
	{
		if (path.size() == words[0].size())
		{
			res.push_back(path);
			return;
		}
		int cur_len = path.size();
		string prefix = "";
		for (int i = 0; i < cur_len; i++) prefix.push_back(path[i][cur_len]);
		vector<string> candidates = getCandidates(prefix);
		for (string ele : candidates) {
			path.push_back(ele);
			dfs(res, path, words);
			path.pop_back();
		}
	}

	vector<string> getCandidates(string& prefix)
	{
		TrieNode* cur = root;
		for (int i = 0; i < prefix.size(); i++)
		{
			if (!cur->next[prefix[i] - 'a']) return {};
			cur = cur->next[prefix[i] - 'a'];
		}
		return cur->Words;
	}

	void addWord(string& word)
	{
		TrieNode* cur = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (!cur->next[word[i] - 'a'])
			{
				cur->next[word[i] - 'a'] = new TrieNode();
			}
			cur->next[word[i] - 'a']->Words.push_back(word);
			cur = cur->next[word[i] - 'a'];
		}
	}
};