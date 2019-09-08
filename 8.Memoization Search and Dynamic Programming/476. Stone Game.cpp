class Solution {
public:
	/**
	 * @param A: An integer array
	 * @return: An integer
	 */
	int stoneGame(vector<int>& A) {
		// write your code here
		if (A.size() < 2) return 0;
		vector<vector<int>> range_sum = get_rangeSum(A);
		vector<vector<int>> dp(A.size(), vector<int>(A.size(), INT_MAX));
		for (int i = A.size() - 1; i >= 0; i--)
		{
			dp[i][i] = 0;
			for (int j = i + 1; j < A.size(); j++)
			{
				for (int k = i; k < j; k++)
				{
					dp[i][j] = min(dp[i][j], range_sum[i][j] + dp[i][k] + dp[k + 1][j]);
				}

			}
		}
		return dp[0][A.size() - 1];
	}

	vector<vector<int>> get_rangeSum(vector<int>& A)
	{
		vector<vector<int>> res(A.size(), vector<int>(A.size(), 0));
		for (int i = 0; i < A.size(); i++)
		{
			res[i][i] = A[i];
			for (int j = i + 1; j < A.size(); j++)
			{
				res[i][j] = res[i][j - 1] + A[j];
			}
		}
		return res;
	}
};