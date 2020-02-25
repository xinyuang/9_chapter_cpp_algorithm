//395. Coins in a Line II
//
//1. for person A, dp[i] is max(sum(x) - sum(y))
//2. for person B, dp[i] is max(sum(y) - sum(x))
//3. so current step dp[i] = max(a[i] - dp[i + 1], a[i] + a[i + 1] - dp[i + 2])

class Solution {
public:
	/**
	 * @param values: a vector of integers
	 * @return: a boolean which equals to true if the first player will win
	 */
	bool firstWillWin(vector<int>& values) {
		// write your code here
		vector<int> dp(values.size() + 1, 0);
		dp[values.size() - 1] = values.back();
		for (int i = values.size() - 2; i >= 0; i--)
		{
			dp[i] = max(values[i] - dp[i + 1], values[i] + values[i + 1] - dp[i + 2]);
		}
		return dp[0] >= 0;
	}
};