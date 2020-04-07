//123. Word Search
//1. dfs to find path
//2. if (board[x][y] == word[path.size()) return
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
		bool res = false;
		vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
		string path = "";
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (res) return res;
				findWord(i, j, visited, res, path, board, word);
			}
		}
		return res;
	}

	void findWord(int x, int y, vector<vector<int>>& visited, bool& res, string& path,
		vector<vector<char>>& board, string& word)
	{
		if (res) return;
		if (board[x][y] != word[path.size()]) return;
		visited[x][y] = 1;
		path.push_back(board[x][y]);
		if (path == word)
		{
			res = true;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (!is_valid(new_x, new_y, board)) continue;
			if (visited[new_x][new_y]) continue;
			findWord(new_x, new_y, visited, res, path, board, word);
		}
		visited[x][y] = 0;
		path.pop_back();
	}

	bool is_valid(int x, int y, vector<vector<char>>& board)
	{
		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) return true;
		return false;
	}
};