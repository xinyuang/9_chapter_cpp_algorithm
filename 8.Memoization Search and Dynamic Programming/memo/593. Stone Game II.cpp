//593. Stone Game II
//1. new A = 2 * A
//2. for loop return min(dp[i][i + A.size() - 1]

class Solution {
public:
	/**
	 * @param A: An integer array
	 * @return: An integer
	 */
	int stoneGame2(vector<int>& A) {
		// write your code here
		if (A.size() == 0) return 0;
		vector<int> sum(A.size() * 2 + 1, 0);
		vector<vector<int>> dp(A.size() * 2, vector<int>(A.size() * 2, INT_MAX));
		for (int i = 0; i < 2 * A.size(); i++)
		{
			sum[i + 1] = sum[i] + A[i % A.size()];
			dp[i][i] = 0;
		}
		for (int i = A.size() * 2 - 2; i >= 0; i--)
		{
			for (int j = i + 1; j < A.size() * 2 && j < i + A.size(); j++)
			{
				for (int k = i; k < j; k++)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j + 1] - sum[i]);
				}
			}
		}
		int res = dp[0][A.size() - 1];
		for (int i = 0; i < A.size(); i++)
		{
			res = min(res, dp[i][i + A.size() - 1]);
		}
		return res;
	}
};