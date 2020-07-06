//1798. Minimum Cost to Merge Stones
//1. dp[left][right][target_pile] is the min_cost that from left to right merge to target_piles
//2. dp[left][right][target_pile] = min(dp[left][i][1] + dp[i + 1][right][target_pile - 1])
//3. if target_pile == 1, return dp[left][right][K] + rangeSum[left][right]


class Solution {
public:
	/**
	 * @param stones:
	 * @param K:
	 * @return: return a integer
	 */
	int mergeStones(vector<int>& stones, int K) {
		// write your code here
		vector<vector<vector<int>>> dp(stones.size(), vector<vector<int>>(stones.size(), vector<int>(K + 1, INT_MAX)));
		vector<vector<int>> rangeSum(stones.size(), vector<int>(stones.size(), 0));
		getRangeSum(rangeSum, stones);
		int res = getMinCost(0, stones.size() - 1, 1, dp, rangeSum, K);
		return res;
	}

	int getMinCost(int i, int j, int p, vector<vector<vector<int>>>& dp, vector<vector<int>>& rangeSum, int K)
	{
		if (dp[i][j][p] != INT_MAX) return dp[i][j][p];
		if (i == j)
		{
			if (p == 1) return 0;
			return -1;
		}
		if (p == 1)
		{
			int res = getMinCost(i, j, K, dp, rangeSum, K);
			if (res == -1) return -1;
			return res + rangeSum[i][j];
		}
		int cost = INT_MAX;
		for (int ptr = i; ptr <= j - p + 1; ptr++)
		{
			int a = getMinCost(i, ptr, 1, dp, rangeSum, K);
			int b = getMinCost(ptr + 1, j, p - 1, dp, rangeSum, K);
			if (a == -1 || b == -1) continue;
			cost = min(cost, a + b);
		}
		if (cost == INT_MAX) dp[i][j][p] = -1;
		else dp[i][j][p] = cost;
		return dp[i][j][p];
	}

	void getRangeSum(vector<vector<int>>& rangeSum, vector<int>& stones)
	{
		for (int i = 0; i < stones.size(); i++) rangeSum[i][i] = stones[i];
		for (int i = stones.size() - 1; i >= 0; i--)
		{
			for (int j = i + 1; j < stones.size(); j++)
			{
				rangeSum[i][j] = rangeSum[i][j - 1] + stones[j];
			}
		}
	}
};



class Solution {
public:
	/**
	 * @param stones:
	 * @param K:
	 * @return: return a integer
	 */
	int mergeStones(vector<int>& stones, int K) {
		// write your code here
		if ((stones.size() - 1) % (K - 1) != 0) {
			return -1;
		}
		vector<vector<int>> rangeSum(stones.size(), vector<int>(stones.size(), 0));
		for (int i = 0; i < stones.size(); i++) rangeSum[i][i] = stones[i];
		for (int i = stones.size() - 1; i >= 0; i--)
		{
			for (int j = i + 1; j < stones.size(); j++)
			{
				rangeSum[i][j] = rangeSum[i][j - 1] + stones[j];
			}
		}
		vector<vector<vector<int>>> dp(stones.size(), vector<vector<int>>(stones.size(),
			vector<int>(K + 1, INT_MAX)));
		for (int i = 0; i < stones.size(); i++) dp[i][i][1] = 0;
		for (int len = 2; len <= stones.size(); len++)
		{
			for (int i = 0; i + len <= stones.size(); i++)
			{
				int j = i + len - 1;
				for (int k = 2; k <= K; k++)
				{
					for (int m = i; m < j; m += (K - 1))
					{
						dp[i][j][k] = min(dp[i][j][k], dp[i][m][1] + dp[m + 1][j][k - 1]);
					}
				}
				dp[i][j][1] = dp[i][j][K] + rangeSum[i][j];
			}
		}
		return dp[0][stones.size() - 1][1];
	}
};

class Solution {
public:
	/**
	 * @param stones:
	 * @param K:
	 * @return: return a integer
	 */
	int mergeStones(vector<int>& stones, int K) {
		// write your code here
		int n = stones.size();
		if ((n - 1) % (K - 1) != 0) return -1;
		vector<int> presum(stones.size() + 1, 0);
		for (int i = 0; i < stones.size(); i++) presum[i + 1] = presum[i] + stones[i];
		vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), INT_MAX));
		for (int i = 0; i < stones.size(); i++) dp[i][i] = 0;
		for (int len = 2; len <= stones.size(); len++)
		{
			for (int i = 0; i <= stones.size() - len; i++)
			{
				int j = i + len - 1;
				for (int k = i; k < j; k += (K - 1))
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
				}
				if ((len - 1) % (K - 1) == 0)
				{
					dp[i][j] = dp[i][j] + presum[j + 1] - presum[i];
				}
			}
		}
		return dp[0][stones.size() - 1];
	}

};

