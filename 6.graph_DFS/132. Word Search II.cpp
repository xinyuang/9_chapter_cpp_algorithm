// Word Search II
//   1. generate prefix set
//   2. traseverse board[i][j]
//   3. DFS    word_set.count(path) return
//      res, path,  board, word_set, prefix, visited, new_x, new_y, used;
class Solution {
public:
	/**
	 * @param board: A list of lists of character
	 * @param words: A list of string
	 * @return: A list of string
	 */
	vector<string> wordSearchII(vector<vector<char>>& board, vector<string>& words) {
		// write your code here
		if (board.size() == 0 || board[0].size() == 0) return {};
		unordered_set<string> word_set(words.begin(), words.end());
		unordered_set<string> prefix;
		for (int i = 0; i < words.size(); i++)
		{
			if (words[i].size() == 0) continue;
			for (int k = 1; k <= words[i].size(); k++)
			{
				prefix.insert(words[i].substr(0, k));
			}
		}

		vector<string> res;
		unordered_set<string> used;

		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
				visited[i][j] = true;
				string cur = "";
				cur += board[i][j];
				if (!prefix.count(cur)) continue;
				dfs(res, cur, board, word_set, prefix, visited, i, j, used);
			}
		}
		return res;
	}

	void dfs(vector<string>& res, string& cur, vector<vector<char>>& board, unordered_set<string>& word_set, \
		unordered_set<string>& prefix, vector<vector<bool>>& visited,
		int x, int y, unordered_set<string>& used)
	{
		if (word_set.count(cur) && !used.count(cur))
		{
			res.push_back(cur);
			used.insert(cur);
		}
		if (!prefix.count(cur)) return;
		for (int i = 0; i < 4; i++)
		{
			int new_x = x + delta_x[i];
			int new_y = y + delta_y[i];
			if (!is_valid(new_x, new_y, board) || visited[new_x][new_y]) continue;
			visited[new_x][new_y] = true;
			cur += board[new_x][new_y];
			dfs(res, cur, board, word_set, prefix, visited, new_x, new_y, used);
			cur.pop_back();
			visited[new_x][new_y] = false;
		}
	}

	bool is_valid(int x, int y, vector<vector<char>>& board)
	{
		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) return true;
		return false;
	}

private:
	int delta_x[4] = { 1,0,-1,0 };
	int delta_y[4] = { 0,1,0,-1 };
};


// Trie Version

//faster because without using unordered_set to store used word
//when new word was added, change TrieNode->Word to ""
//removed the duplicated search using trie

class TrieNode {
public:
	TrieNode* next[26];
	string Word;
	TrieNode() {
		for (int i = 0; i < 26; i++)
		{
			next[i] = nullptr;
		}
		Word = "";
	}
};

class Solution {
private:
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
public:
	/**
	 * @param board: A list of lists of character
	 * @param words: A list of string
	 * @return: A list of string
	 */
	TrieNode* root = new TrieNode();
	vector<string> wordSearchII(vector<vector<char>>& board, vector<string>& words) {
		// write your code here
		if (board.size() == 0 || board[0].size() == 0) return {};

		for (int i = 0; i < words.size(); i++) addWord(words[i]);
		vector<string> res;
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				dfs(i, j, board, root->next[board[i][j] - 'a'], res, visited);
			}
		}
		return res;
	}

	void dfs(int x, int y, vector<vector<char>>& board, TrieNode* cur, vector<string>& res,
		vector<vector<bool>>& visited)
	{
		if (!cur) return;
		if (cur->Word != "")
		{
			res.push_back(cur->Word);
			cur->Word = "";
		}
		visited[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (!is_valid(new_x, new_y, board)) continue;
			if (visited[new_x][new_y]) continue;
			dfs(new_x, new_y, board, cur->next[board[new_x][new_y] - 'a'], res, visited);
		}
		visited[x][y] = false;
	}

	bool is_valid(int x, int y, vector<vector<char>>& board)
	{
		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) return true;
		return false;
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
	}
};