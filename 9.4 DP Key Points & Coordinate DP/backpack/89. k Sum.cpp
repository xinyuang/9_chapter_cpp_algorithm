//89. k Sum
//backpack, add another layer to describe k constraint
//dp[k][A.size()][target]


class Solution {
public:
	/**
	 * @param A: An integer array
	 * @param k: A positive integer (k <= length(A))
	 * @param target: An integer
	 * @return: An integera
	 */
	int kSum(vector<int>& A, int k, int target) {
		// write your code here
		vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(A.size() + 1, vector<int>(target + 1, 0)));
		for (int i = 0; i < A.size(); i++) dp[0][i][0] = 1;

		for (int m = 1; m <= k; m++)
		{
			for (int i = 1; i <= A.size(); i++)
			{
				for (int j = 1; j <= target; j++)
				{
					dp[m][i][j] = dp[m][i - 1][j];
					if (j - A[i - 1] >= 0) dp[m][i][j] += (dp[m - 1][i - 1][j - A[i - 1]]);
				}
			}
		}
		return dp[k][A.size()][target];
	}
};