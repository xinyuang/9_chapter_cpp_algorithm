//123. Word Search
//1. next candicate board[x][y] == word[path.size()]
//2. dfs path for 4 neighbor return path == word

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
		if (board.size() == 0 || board[0].size() == 0) return false;
		vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
		bool res = false;
		string path = "";
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				dfs(res, path, board, i, j, word, visited);
				if (res) return res;
			}
		}
		return res;
	}

	void dfs(bool& res, string& path, vector<vector<char>>& board, int x, int y,
		string& word, vector<vector<int>>& visited)
	{
		if (res) return;
		if (board[x][y] != word[path.size()]) {
			return;
		}
		path.push_back(board[x][y]);
		visited[x][y] = 1;
		if (path == word)
		{
			res = true;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (!is_valid(xx, yy, board)) continue;
			if (visited[xx][yy]) continue;
			dfs(res, path, board, xx, yy, word, visited);
		}
		path.pop_back();
		visited[x][y] = 0;
	}

	bool is_valid(int x, int y, vector<vector<char>>& board)
	{
		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) return true;
		return false;
	}
};