//635. Boggle Game
//1. Use Trie to check word valid or not, global max_count = max(max_count, count)
//2. once find valid word, count++, keep this word, and dfs whole 2d matrix again
//3. if not find, continue for loop dx dy find next dfs
//4. use visited[i][j] to mark the visited position
//5. unlike word search I, II, once find the shortest word, we can return directly


class TrieNode {
public:
	TrieNode* next[26];
	bool isWord;
	TrieNode() {
		for (int i = 0; i < 26; i++)
		{
			next[i] = nullptr;
		}
		isWord = false;
	}
};

class Solution {
private:
	TrieNode* root = new TrieNode();
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
public:
	/*
	 * @param board: a list of lists of character
	 * @param words: a list of string
	 * @return: an integer
	 */
	int boggleGame(vector<vector<char>>& board, vector<string>& words) {
		// write your code here
		for (int i = 0; i < words.size(); i++) addWord(words[i]);
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		int res = 0;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				dfs(res, 0, board, i, j, visited, root->next[board[i][j] - 'a']);
			}
		}
		return res;
	}

	void dfs(int& res, int count, vector<vector<char>>& board, int x, int y,
		vector<vector<bool>>& visited, TrieNode* curNode)
	{
		if (!curNode) return;
		if (visited[x][y]) return;
		visited[x][y] = true;
		if (curNode->isWord)
		{
			count++;
			res = max(res, count);
			for (int i = 0; i < board.size(); i++)
			{
				for (int j = 0; j < board[0].size(); j++)
				{
					dfs(res, count, board, i, j, visited, root->next[board[i][j] - 'a']);
				}
			}
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (!is_valid(new_x, new_y, board)) continue;
			dfs(res, count, board, new_x, new_y, visited, curNode->next[board[new_x][new_y] - 'a']);
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
		cur->isWord = true;
	}
};