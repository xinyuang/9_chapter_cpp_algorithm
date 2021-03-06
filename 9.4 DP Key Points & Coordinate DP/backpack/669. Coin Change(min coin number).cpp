// coin change 
// find the minimum number of coins sums to the target amount
class Solution {
public:
	/**
	 * @param coins: a list of integer
	 * @param amount: a total amount of money amount
	 * @return: the fewest number of coins that you need to make up
	 */
	int coinChange(vector<int>& coins, int amount) {
		// write your code here
		int res = 0;
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < coins.size(); i++)
		{
			for (int j = coins[i]; j <= amount; j++)
			{
				if (dp[j - coins[i]] != INT_MAX) dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}
		}
		if (dp[amount] == INT_MAX) return -1;
		return dp[amount];
	}
};