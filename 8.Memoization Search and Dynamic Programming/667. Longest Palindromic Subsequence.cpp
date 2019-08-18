class Solution {
public:
	/**
	 * @param s: the maximum length of s is 1000
	 * @return: the longest palindromic subsequence's length
	 */
	int longestPalindromeSubseq(string& s) {
		// write your code here
		if (s.size() == 0)return 0;
		int res = 0;
		vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
		dp[s.size() - 1][s.size() - 1] = 1;
		for (int i = s.size() - 2; i >= 0; i--)
		{
			dp[i][i] = 1;
			for (int j = i + 1; j < s.size(); j++)
			{
				if (s[i] == s[j])
				{
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else
				{
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[0][s.size() - 1];
	}
};