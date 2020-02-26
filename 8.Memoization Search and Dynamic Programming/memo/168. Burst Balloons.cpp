//168. Burst Balloons
//1. dp[i][j] is total score of bursting all balloons from i to j, not include i, j
//2. pad dummy balloon to the front and end A[0], A[n + 1] = 1
//3. pad vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2)
//4. dp[i][i + 1] = 0 (i = 0 ~n)
//5. dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + A[k] * A[i] * A[j])



class Solution {
public:
	/**
	 * @param nums: A list of integer
	 * @return: An integer, maximum coins
	 */
	int maxCoins(vector<int>& nums) {
		// write your code here
		vector<int> A(nums.size() + 2, 0);
		A[0] = 1;
		A[nums.size() + 1] = 1;
		for (int i = 0; i < nums.size(); i++) A[i + 1] = nums[i];
		vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2, 0));
		for (int i = nums.size() + 1; i >= 0; i--)
		{
			for (int j = i; j < dp.size(); j++)
			{
				for (int k = i + 1; k <= j - 1; k++)
				{
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]);
				}
			}
		}
		return dp[0][nums.size() + 1];
	}
};