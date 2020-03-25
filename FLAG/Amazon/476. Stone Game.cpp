//476. Stone Game
//1. min(dp[i][k] + dp[k + 1][j] + base)
//2. dp[i][i] = 0

class Solution {
public:
	/**
	 * @param A: An integer array
	 * @return: An integer
	 */
	int stoneGame(vector<int>& A) {
		// write your code here
		if (A.size() == 0) return 0;
		vector<int> presum(A.size() + 1, 0);
		for (int i = 0; i < A.size(); i++) presum[i + 1] = presum[i] + A[i];
		vector<vector<int>> dp(A.size(), vector<int>(A.size(), INT_MAX));
		for (int i = 0; i < A.size(); i++) dp[i][i] = 0;
		for (int len = 2; len <= A.size(); len++)
		{
			for (int i = 0; i <= A.size() - len; i++)
			{
				int j = i + len - 1;
				for (int k = i; k < j; k++)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + presum[j + 1] - presum[i]);
				}
			}
		}
		return dp[0][A.size() - 1];
	}
};