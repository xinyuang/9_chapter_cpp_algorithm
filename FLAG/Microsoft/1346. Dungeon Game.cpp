//1346. Dungeon Game
//1. binary search + dp check, dp[0][0] = hp + dungeon[0][0]
//2. if dp[i][j] <= 0 dp[i][j] = -0xf3f3f3

class Solution {
public:
	/**
	 * @param dungeon: a 2D array
	 * @return: return a integer
	 */
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		// write your code here
		if (dungeon.size() == 0 || dungeon[0].size() == 0) return INT_MAX;
		int left = 1, right = 0xf3f3f3;
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (cansurvive(mid, dungeon)) right = mid;
			else left = mid;
		}
		if (cansurvive(left, dungeon)) return left;
		return right;
	}

	bool cansurvive(int hp, vector<vector<int>>& dungeon)
	{
		vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), 0));
		dp[0][0] = dungeon[0][0] + hp;
		if (dp[0][0] <= 0) return false;
		for (int i = 1; i < dungeon.size(); i++)
		{
			dp[i][0] = dp[i - 1][0] + dungeon[i][0];
			if (dp[i][0] <= 0) dp[i][0] = -0xf3f3f3;
		}
		for (int j = 1; j < dungeon[0].size(); j++)
		{
			dp[0][j] = dp[0][j - 1] + dungeon[0][j];
			if (dp[0][j] <= 0) dp[0][j] = -0xf3f3f3;
		}
		for (int i = 1; i < dungeon.size(); i++)
		{
			for (int j = 1; j < dungeon[0].size(); j++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + dungeon[i][j];
				if (dp[i][j] <= 0) dp[i][j] = -0xf3f3f3;
			}
		}
		return dp[dungeon.size() - 1][dungeon[0].size() - 1] > 0;
	}
};