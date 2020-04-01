//1798. Minimum Cost to Merge Stones
//
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
		vector<int> presum(stones.size() + 1, 0);
		for (int i = 0; i < stones.size(); i++) presum[i + 1] = presum[i] + stones[i];
		vector<vector<vector<int>>> dp(stones.size(), vector<vector<int>>(stones.size(),
			vector<int>(K + 1, INT_MAX)));
		int res = getCost(dp, 0, stones.size() - 1, 1, K, presum);
		return res;
	}

	int getCost(vector<vector<vector<int>>>& dp, int start, int end, int pile, int K, vector<int>& presum)
	{
		if (dp[start][end][pile] != INT_MAX) return dp[start][end][pile];
		if (start == end)
		{
			if (pile == 1) return 0;
			return -1;
		}
		if (pile == 1)
		{
			int res = getCost(dp, start, end, K, K, presum);
			if (res == -1) return -1;
			dp[start][end][pile] = res + presum[end + 1] - presum[start];
			return dp[start][end][pile];
		}
		int cur_cost = INT_MAX;
		for (int k = start; k < end; k++)
		{
			int first_pile = getCost(dp, start, k, 1, K, presum);
			int rest_pile = getCost(dp, k + 1, end, pile - 1, K, presum);
			if (first_pile == -1 || rest_pile == -1) continue;
			cur_cost = min(cur_cost, first_pile + rest_pile);
		}
		if (cur_cost == INT_MAX) cur_cost = -1;
		dp[start][end][pile] = cur_cost;
		return cur_cost;
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
		if ((stones.size() - 1) % (K - 1) != 0) return -1;
		vector<int> presum(stones.size() + 1, 0);
		for (int i = 0; i < stones.size(); i++) presum[i + 1] = presum[i] + stones[i];
		vector<vector<vector<int>>> dp(stones.size(), vector<vector<int>>(stones.size(),
			vector<int>(K + 1, INT_MAX)));
		for (int i = 0; i < stones.size(); i++) dp[i][i][1] = 0;
		for (int len = 2; len <= stones.size(); len++)
		{
			for (int i = 0; i <= stones.size() - len; i++)
			{
				int j = i + len - 1;
				for (int k = 2; k <= K; k++)
				{
					for (int m = i; m < j; m += (K - 1))
					{
						dp[i][j][k] = min(dp[i][j][k], dp[i][m][1] + dp[m + 1][j][k - 1]);
					}
				}
				dp[i][j][1] = dp[i][j][K] + presum[j + 1] - presum[i];
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
					dp[i][j] += presum[j + 1] - presum[i];
				}
			}
		}
		return dp[0][stones.size() - 1];
	}
};