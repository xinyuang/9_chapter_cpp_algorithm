// Knight Shortest Path II   left to right, no dependency
//      *
//    *
//        o
//    *
//      *
class Solution {
public:
	/**
	 * @param grid: a chessboard included 0 and 1
	 * @return: the shortest path
	 */
	int shortestPath2(vector<vector<bool>>& grid) {
		// write your code here
		if (grid.size() == 0 || grid[0].size() == 0) return -1;
		vector<vector<int>> dp(grid.size(), vector<int>(3, INT_MAX));
		int delta_x[4] = { 2,1,-1,-2 };
		int delta_y[4] = { -1,-2,-2,-1 };
		dp[0][0] = 0;
		for (int j = 1; j < grid[0].size(); j++)
		{
			for (int i = 0; i < grid.size(); i++)
			{
				dp[i][j % 3] = INT_MAX;
			}

			for (int i = 0; i < grid.size(); i++)
			{
				if (grid[i][j] == 1) continue;
				for (int k = 0; k < 4; k++)
				{
					int prev_x = i + delta_x[k];
					int prev_y = j + delta_y[k];
					if (!is_Valid(prev_x, prev_y, grid) || dp[prev_x][prev_y % 3] == INT_MAX) continue;
					dp[i][j % 3] = min(dp[i][j % 3], dp[prev_x][prev_y % 3] + 1);
				}
			}
		}
		if (dp[grid.size() - 1][(grid[0].size() - 1) % 3] == INT_MAX) return -1;
		return dp[grid.size() - 1][(grid[0].size() - 1) % 3];
	}

	bool is_Valid(int x, int y, vector<vector<bool>>& grid)
	{
		if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size()) return true;
		return false;
	}
};


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
// Knight Shortest Path
// 8 direction, cannot use DFS
class Solution {
public:
	/**
	 * @param grid: a chessboard included 0 (false) and 1 (true)
	 * @param source: a point
	 * @param destination: a point
	 * @return: the shortest path
	 */
	int shortestPath(vector<vector<bool>>& grid, Point& source, Point& destination) {
		// write your code here
		int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
		int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };
		queue<Point> q;
		q.push(source);
		grid[source.x][source.y] = true;
		int step = 1;
		while (!q.empty())
		{
			int len = q.size();
			for (int i = 0; i < len; i++)
			{
				Point cur = q.front();
				q.pop();

				for (int k = 0; k < 8; k++)
				{
					int new_x = cur.x + dx[k];
					int new_y = cur.y + dy[k];
					if (!isValid(new_x, new_y, grid)) continue;
					if (new_x == destination.x && new_y == destination.y) return step;
					Point newPoint = Point(new_x, new_y);
					if (grid[new_x][new_y] == 0)
					{
						q.push(newPoint);
						grid[new_x][new_y] = 1;
					}
				}
			}
			step++;
		}
		return -1;
	}

	bool isValid(int x, int y, vector<vector<bool>>& grid)
	{
		int m = grid.size();
		int n = grid[0].size();
		if (x >= 0 && x < m && y >= 0 && y < n) return true;
		return false;
	}
};