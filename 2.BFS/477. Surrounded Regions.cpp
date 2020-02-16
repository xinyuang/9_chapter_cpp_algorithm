//477. Surrounded Regions
//
//bfs frame, change O to T
//for loop i,j, change O to X, T to O

class Solution {
private:
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
public:
	/*
	 * @param board: board a 2D board containing 'X' and 'O'
	 * @return: nothing
	 */
	void surroundedRegions(vector<vector<char>>& board) {
		// write your code here
		if (board.size() == 0 || board[0].size() == 0) return;
		for (int i = 0; i < board.size(); i++)
		{
			if (board[i][0] == 'O') bfs(i, 0, board, 'O', 'T');
			if (board[i][board[0].size() - 1] == 'O') bfs(i, board[0].size() - 1, board, 'O', 'T');
		}
		for (int j = 1; j < board[0].size() - 1; j++)
		{
			if (board[0][j] == 'O') bfs(0, j, board, 'O', 'T');
			if (board[board.size() - 1][j] == 'O') bfs(board.size() - 1, j, board, 'O', 'T');
		}
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (board[i][j] == 'O') board[i][j] = 'X';
				if (board[i][j] == 'T') board[i][j] = 'O';
			}
		}
	}

	void bfs(int i, int j, vector<vector<char>>& board, char source, char target)
	{
		board[i][j] = target;
		queue<pair<int, int>> queue;
		queue.push({ i,j });
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		visited[i][j] = true;
		while (!queue.empty())
		{
			pair<int, int> cur = queue.front(); queue.pop();
			int x = cur.first;
			int y = cur.second;
			for (int i = 0; i < 4; i++)
			{
				int new_x = x + dx[i];
				int new_y = y + dy[i];
				if (!is_valid(new_x, new_y, board)) continue;
				if (visited[new_x][new_y]) continue;
				visited[new_x][new_y] = true;
				if (board[new_x][new_y] == source)
				{
					board[new_x][new_y] = target;
					queue.push({ new_x,new_y });
				}
			}
		}

	}

	bool is_valid(int x, int y, vector<vector<char>>& board)
	{
		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) return true;
		return false;
	}
};