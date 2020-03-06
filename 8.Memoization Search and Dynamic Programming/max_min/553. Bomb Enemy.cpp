//553. Bomb Enemy
//1. padding frame, presum left, right, up, down(n + 2, n + 2)
//2. grid[i - 1][j - 1] == '0' res = max(res, left[i][j - 1] + right[i][j + 1] + up[i - 1][j] + down[i + 1][j])

class Solution {
public:
	/**
	 * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
	 * @return: an integer, the maximum enemies you can kill using one bomb
	 */
	int maxKilledEnemies(vector<vector<char>>& grid) {
		// write your code here
		if (grid.size() == 0 || grid[0].size() == 0) return 0;
		vector<vector<int>> left(grid.size() + 2, vector<int>(grid[0].size() + 2, 0));
		vector<vector<int>> right(grid.size() + 2, vector<int>(grid[0].size() + 2, 0));
		vector<vector<int>> up(grid.size() + 2, vector<int>(grid[0].size() + 2, 0));
		vector<vector<int>> down(grid.size() + 2, vector<int>(grid[0].size() + 2, 0));
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				left[i + 1][j + 1] = left[i + 1][j];
				if (grid[i][j] == 'E') left[i + 1][j + 1]++;
				if (grid[i][j] == 'W') left[i + 1][j + 1] = 0;
			}
		}
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = grid[0].size() - 1; j >= 0; j--)
			{
				right[i + 1][j + 1] = right[i + 1][j + 2];
				if (grid[i][j] == 'E') right[i + 1][j + 1]++;
				if (grid[i][j] == 'W') right[i + 1][j + 1] = 0;
			}
		}
		for (int j = 0; j < grid[0].size(); j++)
		{
			for (int i = 0; i < grid.size(); i++)
			{
				up[i + 1][j + 1] = up[i][j + 1];
				if (grid[i][j] == 'E') up[i + 1][j + 1]++;
				if (grid[i][j] == 'W') up[i + 1][j + 1] = 0;
			}
		}
		for (int j = 0; j < grid[0].size(); j++)
		{
			for (int i = grid.size() - 1; i >= 0; i--)
			{
				down[i + 1][j + 1] = down[i + 2][j + 1];
				if (grid[i][j] == 'E') down[i + 1][j + 1]++;
				if (grid[i][j] == 'W') down[i + 1][j + 1] = 0;
			}
		}
		int max_kill = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '0') {
					max_kill = max(max_kill, left[i + 1][j] + right[i + 1][j + 2] + up[i][j + 1] + down[i + 2][j + 1]);

				}
			}
		}
		return max_kill;
	}
};