//440. Backpack III
//
//1. complete backpack, dp(m + 1, 0)
//2. from front to end, if (i - A[j] >= 0) dp[i] = max(dp[i], dp[i - A[j]] + V[j]);

class Solution {
public:
	/**
	 * @param A: an integer array
	 * @param V: an integer array
	 * @param m: An integer
	 * @return: an array
	 */
	int backPackIII(vector<int>& A, vector<int>& V, int m) {
		// write your code here
		vector<int> dp(m + 1, 0);
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (j - A[i] >= 0) dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
			}
		}
		return dp.back();
	}
};