//132. Word Search II
//1. prefix filter
//2. global used set, to ensure no duplicated answer
//3. dfs to find all pathes
//time O(mn * 4 ^ k)
//space O(4mn)
//1. use Trie{ next[26], string word } to store prefix
//2. visited[i][j] dfs i, j. if (cur_node->word != "") push_back to res, and set word to empty
//(in this way, we save one unordered_set to store non - duplicated answer)

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
	TrieNode* root;
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
		TrieNode* root = new TrieNode();
		for (int i = 0; i < words.size(); i++)
		{
			addWord(root, words[i]);
		}
		vector<string> res;
		string path = "";
		vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				TrieNode* cur = root->next[board[i][j] - 'a'];
				dfs(i, j, cur, board, res, visited);
			}
		}
		return res;
	}

	void dfs(int x, int y, TrieNode* cur, vector<vector<char>>& board, vector<string>& res,
		vector<vector<int>>& visited)
	{

		if (visited[x][y]) return;
		if (!cur) return;
		visited[x][y] = 1;
		if (cur->Word != "")
		{
			res.push_back(cur->Word);
			cur->Word = "";
		}
		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (!is_valid(new_x, new_y, board)) continue;
			TrieNode* next = cur->next[board[new_x][new_y] - 'a'];
			dfs(new_x, new_y, next, board, res, visited);
		}
		visited[x][y] = 0;
	}

	bool is_valid(int x, int y, vector<vector<char>>& board)
	{
		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) return true;
		return false;
	}

	void addWord(TrieNode* root, string word)
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
