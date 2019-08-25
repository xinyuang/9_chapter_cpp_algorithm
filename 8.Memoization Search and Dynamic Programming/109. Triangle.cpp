class Solution {
public:
	/**
	 * @param triangle: a list of lists of integers
	 * @return: An integer, minimum path sum
	 */
	int minimumTotal(vector<vector<int>>& triangle) {
		// write your code here
		vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));
		vector<vector<bool>> visited(triangle.size(), vector<bool>(triangle.size(), false));
		int res = divideConquer(triangle, dp, visited, 0, 0);
		return res;
	}

	int divideConquer(vector<vector<int>>& triangle, vector<vector<int>>& dp, vector<vector<bool>>& visited, int x, int y)
	{
		if (x >= triangle.size() || y >= triangle.size()) return 0;
		int down, down_right;
		if (x < triangle.size() - 1 && visited[x + 1][y]) down = dp[x + 1][y];
		else down = divideConquer(triangle, dp, visited, x + 1, y);
		if (x < triangle.size() - 1 && y < triangle.size() - 1 && visited[x + 1][y + 1]) down_right = dp[x + 1][y + 1];
		else down_right = divideConquer(triangle, dp, visited, x + 1, y + 1);
		int cur = min(down, down_right) + triangle[x][y];
		dp[x][y] = cur;
		visited[x][y] = true;
		return cur;
	}
};