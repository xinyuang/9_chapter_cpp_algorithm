//132. Word Search II
//use TrieNode faster because without using unordered_set to store used word
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
	TrieNode* root = new TrieNode();
	vector<vector<bool>> visited;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
public:
	/**
	 * @param board: A list of lists of character
	 * @param words: A list of string
	 * @return: A list of string
	 */
	vector<string> wordSearchII(vector<vector<char>>& board, vector<string>& words) {
		// write your code here
		if (board.size() == 0 || board[0].size() == 0) return {};
		for (int i = 0; i < words.size(); i++) addWord(words[i]);
		vector<string> res;

		visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				dfs(i, j, board, res, root->next[board[i][j] - 'a']);
			}
		}
		return res;
	}

	void dfs(int x, int y, vector<vector<char>>& board, vector<string>& res, TrieNode* curNode)
	{
		if (!curNode) return;
		if (visited[x][y]) return;
		visited[x][y] = true;
		if (curNode->Word != "")
		{
			res.push_back(curNode->Word);
			curNode->Word = "";
		}
		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (!is_valid(new_x, new_y, board)) continue;
			if (visited[new_x][new_y]) continue;
			dfs(new_x, new_y, board, res, curNode->next[board[new_x][new_y] - 'a']);
		}
		visited[x][y] = false;
	}

	bool is_valid(int x, int y, vector<vector<char>>& board)
	{
		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) return true;
		return false;
	}

	void addWord(string word)
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