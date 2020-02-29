//562. Backpack IV
//
//1.[2, 3], [3, 2] is same solution, So for loop number first
//2. then for loop i cur to target, dp[i] += dp[i - cur]

class Solution {
public:
	/**
	 * @param nums: an integer array and all positive numbers, no duplicates
	 * @param target: An integer
	 * @return: An integer
	 */
	int backPackIV(vector<int>& nums, int target) {
		// write your code here
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 1; j <= target; j++)
			{
				if (j - nums[i] >= 0) dp[j] += dp[j - nums[i]];
			}
		}
		return dp.back();
	}
};