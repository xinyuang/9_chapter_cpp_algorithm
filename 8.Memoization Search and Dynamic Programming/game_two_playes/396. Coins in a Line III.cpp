//396. Coins in a Line III
//
//1. init f[n] where the last step is dp[i][i] = values[i]
//2. dp[i][j] = max(v[i] - dp[i + 1][j], v[j] - dp[i][j + 1])
//3. return dp[0][v.size() - 1] >= 0

class Solution {
public:
	/**
	 * @param values: a vector of integers
	 * @return: a boolean which equals to true if the first player will win
	 */
	bool firstWillWin(vector<int>& values) {
		// write your code here
		vector<vector<int>> dp(values.size(), vector<int>(values.size(), 0));
		for (int i = 0; i < values.size(); i++) dp[i][i] = values[i];
		for (int i = values.size() - 1; i >= 0; i--)
		{
			for (int j = i + 1; j < values.size(); j++)
			{
				dp[i][j] = max(values[i] - dp[i + 1][j], values[j] - dp[i][j - 1]);
			}
		}
		return dp[0][values.size() - 1] >= 0;
	}
};