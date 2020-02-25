//394. Coins in a Line
//1. dp[0] = false, dp[1] = true
//2. dp[i] == (dp[i - 1] == false || dp[i - 2] == false)

class Solution {
public:
	/**
	 * @param n: An integer
	 * @return: A boolean which equals to true if the first player will win
	 */
	bool firstWillWin(int n) {
		// write your code here
		vector<bool> dp(n + 1);
		dp[0] = false;
		dp[1] = true;
		for (int i = 2; i <= n; i++)
		{
			dp[i] = (!dp[i - 1] || !dp[i - 2]);
		}
		return dp.back();
	}
};