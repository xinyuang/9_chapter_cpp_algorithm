//91. Minimum Adjustment Cost
//1. dp[i][k] means the whole cost till th ith number change to k
//2. dp[i][k] = min(dp[i][k], dp[i][j] + abs(A[i - 1] - target)) where j E[k - target, k + target

class Solution {
public:
	/*
	 * @param A: An integer array
	 * @param target: An integer
	 * @return: An integer
	 */
	int MinAdjustmentCost(vector<int>& A, int target) {
		// write your code here
		vector<vector<int>> dp(101, vector<int>(A.size() + 1, INT_MAX));
		for (int i = 0; i <= 100; i++) dp[i][0] = 0;
		for (int j = 1; j <= A.size(); j++)
		{
			for (int i = 0; i <= 100; i++)
			{
				for (int k = i - target; k <= i + target; k++)
				{

					if (k >= 0 && k <= 100) {
						if (dp[k][j - 1] != INT_MAX) dp[i][j] = min(dp[i][j], dp[k][j - 1] + abs(A[j - 1] - k));
					}
				}
			}
		}
		int res = INT_MAX;
		for (int i = 0; i <= 100; i++) res = min(res, dp[i][A.size()]);
		return res;
	}
};