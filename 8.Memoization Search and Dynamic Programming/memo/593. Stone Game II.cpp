//593. Stone Game II
//1. A, right shift A 1 get A_new
//2. return min(stroneGame(A), stoneGame(A_new);

class Solution {
private:
	vector<int> presum;
public:
	/**
	 * @param A: An integer array
	 * @return: An integer
	 */
	int stoneGame2(vector<int>& A) {
		// write your code here
		if (A.size() == 0 || A.size() == 1) return 0;
		vector<int> newA(A.size(), 0);
		for (int i = 0; i < A.size() - 1; i++) newA[i] = A[i + 1];
		newA[A.size() - 1] = A[0];
		int ori_max = findMin(A);
		int shift_max = findMin(newA);
		return min(ori_max, shift_max);
	}

	int findMin(vector<int>& A)
	{
		vector<vector<int>> dp(A.size(), vector<int>(A.size(), INT_MAX));
		for (int i = 0; i < A.size(); i++) dp[i][i] = 0;
		presum = getPresum(A);
		for (int i = A.size() - 2; i >= 0; i--)
		{
			for (int j = i + 1; j < A.size(); j++)
			{
				int score = presum[j + 1] - presum[i];
				for (int k = i; k < j; k++)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + score);
				}
			}
		}
		return dp[0][A.size() - 1];
	}

	vector<int> getPresum(vector<int> A)
	{
		vector<int> presum(A.size() + 1, 0);
		for (int i = 0; i < A.size(); i++)
		{
			presum[i + 1] = presum[i] + A[i];
		}
		return presum;
	}

};