//118. Distinct Subsequences
//1. dp[S.size() + 1][T.size() + 1]  dp[i][0] = 1
//2. dp[i][j] = dp[i - 1][j] if (S[i - 1] == T[j - 1]) dp[i][j] += dp[i - 1][j - 1]


class Solution {
public:
	/**
	 * @param S: A string
	 * @param T: A string
	 * @return: Count the number of distinct subsequences
	 */
	int numDistinct(string& S, string& T) {
		// write your code here
		vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, 0));
		dp[0][0] = 1;
		for (int i = 1; i <= S.size(); i++) dp[i][0] = 1;
		for (int i = 1; i <= S.size(); i++)
		{
			for (int j = 1; j <= T.size(); j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (S[i - 1] == T[j - 1]) dp[i][j] += dp[i - 1][j - 1];
			}
		}
		return dp[S.size()][T.size()];
	}
};