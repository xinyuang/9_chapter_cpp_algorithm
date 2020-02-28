//77. Longest Common Subsequence
//1. dp[i][j] is the LCS of A[:i] and B[:j]
//2. dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1](A[i - 1] == B[j - 1])

class Solution {
public:
	/**
	 * @param A: A string
	 * @param B: A string
	 * @return: The length of longest common subsequence of A and B
	 */
	int longestCommonSubsequence(string& A, string& B) {
		// write your code here
		vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
		for (int i = 1; i <= A.size(); i++)
		{
			for (int j = 1; j <= B.size(); j++)
			{
				if (A[i - 1] == B[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[A.size()][B.size()];
	}
};