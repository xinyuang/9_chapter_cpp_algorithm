// 563. Backpack V
// The total number of solution (each coin can only be selected one time)
class Solution {
public:
	/**
	 * @param nums: an integer array and all positive numbers
	 * @param target: An integer
	 * @return: An integer
	 */
	int backPackV(vector<int>& nums, int target) {
		// write your code here
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = target; j >= nums[i]; j--)
			{
				dp[j] += dp[j - nums[i]];
			}
		}
		return dp[target];
	}
};