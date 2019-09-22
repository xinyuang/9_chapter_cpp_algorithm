class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		// write your solution here
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
		int res = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				int now = dfs(dp, matrix, i, j);
				if (res < now) res = now;
			}
		}
		return res;
	}

	int dfs(vector<vector<int>>& dp, vector<vector<int>>& matrix, int x, int y)
	{
		if (dp[x][y] != 0) return dp[x][y];
		dp[x][y] = 1;
		for (int i = 0; i < 4; i++)
		{
			int new_x = x + delta_x[i];
			int new_y = y + delta_y[i];
			if (!is_valid(new_x, new_y, matrix)) continue;
			if (matrix[new_x][new_y] <= matrix[x][y]) continue;
			int cur = dfs(dp, matrix, new_x, new_y) + 1;
			if (dp[x][y] < cur) dp[x][y] = cur;
		}
		return dp[x][y];
	}

	bool is_valid(int x, int y, vector<vector<int>>& matrix)
	{
		if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size()) return true;
		return false;
	}

private:
	int delta_x[4] = { 0,1,0,-1 };
	int delta_y[4] = { 1,0,-1,0 };
};