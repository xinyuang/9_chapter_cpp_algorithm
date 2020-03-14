//123. Word Search
//1. dfs to find path
//2. use prefix to check path valid or not
//3. return immediately if res is find

class Solution {
private:
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
public:
	/**
	 * @param board: A list of lists of character
	 * @param word: A string
	 * @return: A boolean
	 */
	bool exist(vector<vector<char>>& board, string& word) {
		// write your code here
		unordered_set<string> prefix;
		for (int i = 1; i <= word.size(); i++)
		{
			string cur = word.substr(0, i);
			prefix.insert(cur);
		}
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (board[i][j] != word[0]) continue;
				string path = word.substr(0, 1);
				bool res = false;
				vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
				visited[i][j] = 1;
				findWord(res, path, board, word, visited, i, j, prefix);
				if (res) return res;
			}
		}
		return false;
	}

	void findWord(bool& res, string& path, vector<vector<char>>& board,
		string& word, vector<vector<int>>& visited, int x, int y, unordered_set<string>& prefix)
	{
		if (res) return;
		if (!prefix.count(path)) return;
		if (path.size() == word.size())
		{
			if (path == word) {

				res = true;
			}
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (!is_valid(new_x, new_y, board) || visited[new_x][new_y]) continue;
			path.push_back(board[new_x][new_y]);
			visited[new_x][new_y] = 1;
			findWord(res, path, board, word, visited, new_x, new_y, prefix);
			path.pop_back();
			visited[new_x][new_y] = 0;
		}
	}

	bool is_valid(int x, int y, vector<vector<char>>& board)
	{
		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) return true;
		return false;
	}
};