//912. Best Meeting Point
//1. find houses vector < pair<int, int>>
//2. get horizontal and vertical cost
//3. cur_cost = horizontal[i] + vertical[j]

class Solution {
public:
	/**
	 * @param grid: a 2D grid
	 * @return: the minimize travel distance
	 */
	int minTotalDistance(vector<vector<int>>& grid) {
		// Write your code here
		if (grid.size() == 0 || grid[0].size() == 0) return -1;
		vector<int> horizontal(grid.size(), 0);
		vector<int> vertical(grid[0].size(), 0);
		vector<pair<int, int>> homes;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == 0) continue;
				homes.push_back({ i,j });
			}
		}

		for (int i = 0; i < grid.size(); i++)
		{
			int cost = 0;
			for (auto h : homes)
			{
				cost += abs(h.first - i);
			}
			horizontal[i] = cost;
		}

		for (int j = 0; j < grid[0].size(); j++)
		{
			int cost = 0;
			for (auto h : homes)
			{
				cost += abs(h.second - j);
			}
			vertical[j] = cost;
		}


		int min_cost = INT_MAX;
		for (int j = 0; j < grid[0].size(); j++)
		{
			for (int i = 0; i < grid.size(); i++)
			{
				int ttl_cost = horizontal[i] + vertical[j];
				min_cost = min(min_cost, ttl_cost);
			}
		}
		return min_cost;
	}
};