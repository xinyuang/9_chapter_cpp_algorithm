//574. Build Post Office
//1. dist = (sum(rowCost) + sum(colCost))
//2. do projection on row and column, calculate current row / column cost

class Solution {
public:
	/**
	 * @param grid: a 2D grid
	 * @return: An integer
	 */
	int shortestDistance(vector<vector<int>>& grid) {
		// write your code here
		vector<pair<int, int>> house;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == 1) house.push_back({ i,j });
			}
		}
		vector<int> columsCost;
		for (int i = 0; i < grid[0].size(); i++)
		{
			int cur_cost = 0;
			for (auto point : house)
			{
				cur_cost += abs(i - point.second);
			}
			columsCost.push_back(cur_cost);
		}
		vector<int> rowCost;
		for (int i = 0; i < grid.size(); i++)
		{
			int cur_cost = 0;
			for (auto point : house)
			{
				cur_cost += abs(i - point.first);
			}
			rowCost.push_back(cur_cost);
		}
		int min_dist = INT_MAX;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] != 0) continue;
				int cur_dist = rowCost[i] + columsCost[j];
				min_dist = min(min_dist, cur_dist);
			}
		}
		return min_dist;
	}
};