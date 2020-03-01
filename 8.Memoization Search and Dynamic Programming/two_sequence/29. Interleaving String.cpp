//29. Interleaving String
//
//1. dp[i][j] is true if s1[:i] s2[:j] can interleaving s3[:i + j]
//2. dp[0][0] = true, dp[i][0] = s1[:i] == s3[:i], dp[0][j] = s2[:j] == s3[:j]
//3. dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j] || (s2[i - 1] == s3[i + j - 1] && dp[i][j - 1])

class Solution {
public:
	/**
	 * @param s1: A string
	 * @param s2: A string
	 * @param s3: A string
	 * @return: Determine whether s3 is formed by interleaving of s1 and s2
	 */
	bool isInterleave(string& s1, string& s2, string& s3) {
		// write your code here
		if (s1.size() + s2.size() != s3.size()) return false;
		vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		dp[0][0] = true;
		for (int i = 0; i < s1.size(); i++) dp[i + 1][0] = dp[i][0] && (s1[i] == s3[i]);
		for (int i = 0; i < s2.size(); i++) dp[0][i + 1] = dp[0][i] && (s2[i] == s3[i]);
		for (int i = 1; i <= s1.size(); i++)
		{
			for (int j = 1; j <= s2.size(); j++)
			{
				dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
		return dp[s1.size()][s2.size()];
	}
};