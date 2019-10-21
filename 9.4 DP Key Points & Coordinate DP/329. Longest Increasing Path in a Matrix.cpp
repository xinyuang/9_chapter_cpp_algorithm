// Longest Increasing Path in a Matrix
// cur_long = max(cur_long, neighbor_long + 1)
class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		// write your solution here
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
		int longest = 1;
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				int cur_long = find(matrix, dp, i, j);
				longest = max(cur_long, longest);
			}
		}
		return longest;
	}

	int find(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y)
	{
		if (dp[x][y] != 0) return dp[x][y];
		dp[x][y] = 1;
		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (!is_valid(new_x, new_y, matrix)) continue;
			if (matrix[new_x][new_y] <= matrix[x][y]) continue;
			int cur = find(matrix, dp, new_x, new_y) + 1;
			dp[x][y] = max(cur, dp[x][y]);
		}
		return dp[x][y];
	}

	bool is_valid(int x, int y, vector<vector<int>>& matrix)
	{
		if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size()) return true;
		return false;
	}

private:
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };
};