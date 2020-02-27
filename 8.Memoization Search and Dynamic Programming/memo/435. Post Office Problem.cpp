//435. Post Office Problem
//1. dp[i][j] means minimun cost to build i office in[0, j] house
//2. dp[i][j] = min(dp[i][j], dp[i - 1][j - x] + lastOne[j - x][j]) x E[1, j]
//3. lastOne[l][r] means minimum cost to build one office for houses[l, r]
//4. init dp[k + 1][n + 1], dp[0][j] = inf(0x3f3f3f3f) dp[0][0] = 0, dp[i][j] = 0 (i >= j)
//5. when k >= A.size() return 0

class Solution {
public:
	/**
	 * @param A: an integer array
	 * @param k: An integer
	 * @return: an integer
	 */
	int postOffice(vector<int>& A, int k) {
		// write your code here
		if (A.size() == 0 || k >= A.size()) return 0;
		sort(A.begin(), A.end());
		vector<vector<int>> dp(A.size(), vector<int>(k, 0xf3f3f3));
		dp[0][0] = 0;
		for (int i = 0; i < A.size(); i++) dp[i][0] = dist(-1, i, A);
		for (int j = 0; j < k; j++) dp[0][j] = 0;
		for (int i = 1; i < A.size(); i++)
		{
			for (int n = 1; n <= k && n <= i; n++)
			{
				for (int j = n - 1; j < i; j++)
				{
					dp[i][n] = min(dp[i][n], dp[j][n - 1] + dist(j, i, A));
				}
			}
		}
		return dp[A.size() - 1][k - 1];
	}

	int dist(int i, int j, vector<int>& A)
	{
		int mid = (i + 1 + j) / 2;
		int res = 0;
		for (int k = i + 1; k <= j; k++)
		{
			res += abs(A[k] - A[mid]);
		}
		return res;
	}
};
