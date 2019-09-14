class Solution {
public:
	/**
	 * @param grid: a boolean 2D matrix
	 * @return: an integer
	 */



	int numIslands(vector<vector<bool>>& grid) {
		// write your code here
		int m = grid.size();
		if (m == 0) return 0;
		int n = grid[0].size();
		if (n == 0) return 0;
		int res = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{

				if (grid[i][j] == 1)
				{
					bfs(i, j, grid, m, n);
					res++;
				}
			}
		}
		return res;
	}

	void bfs(int x, int y, vector<vector<bool>>& grid, int m, int n)
	{
		queue<pair<int, int>> q;
		q.push(make_pair(x, y));
		while (!q.empty())
		{
			pair<int, int> coor = q.front();
			q.pop();
			int x_coor[4] = { 0,-1,0,1 };
			int y_coor[4] = { 1,0,-1,0 };
			for (int i = 0; i < 4; i++)
			{
				int new_x = coor.first + x_coor[i];
				int new_y = coor.second + y_coor[i];
				if (new_x < m && new_x >= 0 && new_y < n && new_y >= 0)
				{
					if (grid[new_x][new_y] == 1)q.push(make_pair(new_x, new_y));
					grid[new_x][new_y] = 0;
				}
			}
		}
	}
};