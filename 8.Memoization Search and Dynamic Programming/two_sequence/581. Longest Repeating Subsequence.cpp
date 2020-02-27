//581. Longest Repeating Subsequence
//1. split out two substr in sequence, each character only be used once
//2.              if (str[i - 1] == str[j - 1] && i != j) dp[i][j] = dp[i - 1][j - 1] + 1;
//				else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

class Solution {
public:
	/**
	 * @param str: a string
	 * @return: the length of the longest repeating subsequence
	 */
	int longestRepeatingSubsequence(string& str) {
		// write your code here
		vector<vector<int>> dp(str.size() + 1, vector<int>(str.size() + 1, 0));
		for (int i = 1; i < dp.size(); i++)
		{
			for (int j = 1; j < dp.size(); j++)
			{
				if (str[i - 1] == str[j - 1] && i != j) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[str.size()][str.size()];
	}
};