// 564. Combination Sum IV
// The total number of solution (each coin can be select many times)
// [1,2,1] and [1,1,2] are different solutions
class Solution {
public:
	/**
	 * @param nums: an integer array and all positive numbers, no duplicates
	 * @param target: An integer
	 * @return: An integer
	 */
	int backPackVI(vector<int>& nums, int target) {
		// write your code here

		//[1,2,3]  tar 5

		// 0,1,2,3,4,5
		// 1 1 2 4 7 13
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < target; i++)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (i + nums[j] <= target) dp[i + nums[j]] += dp[i];
			}
		}
		return dp[target];
	}
};