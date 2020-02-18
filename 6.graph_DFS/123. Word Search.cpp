//123. Word Search
//1. iterate through i, j  dfs(res, path, visited)
//2. if board[x][y] != word[path.size()] return; parh.size() == word.size() res.push_back(path)
//3. visited[x][y] = 1, path.push_back(board[x][y]), for loop 4 neighbors, visited[x][y] = 0, path pop

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
		string path = "";
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				dfs(res, path, i, j, board, word, visited);
				if (res) return res;
			}
		}
		return res;
	}

	void dfs(bool& res, string& path, int x, int y, vector<vector<char>>& board,
		string& word, vector<vector<bool>>& visited)
	{
		if (res) return;
		if (board[x][y] != word[path.size()]) return;
		path.push_back(board[x][y]);
		visited[x][y] = true;
		if (path.size() == word.size())
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
			dfs(res, path, new_x, new_y, board, word, visited);
		}
		visited[x][y] = false;
		path.pop_back();
	}

	bool is_valid(int x, int y, vector<vector<char>>& board)
	{
		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) return true;
		return false;
	}
};