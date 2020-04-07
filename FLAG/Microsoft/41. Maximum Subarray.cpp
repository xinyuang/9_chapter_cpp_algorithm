//41. Maximum Subarray
//accumulate sum if negative, reset to 0

class Solution {
public:
	/**
	 * @param nums: A list of integers
	 * @return: An integer indicate the sum of max subarray
	 */
	int maxSubArray(vector<int>& nums) {
		// write your code here
		if (nums.size() == 0) return 0;
		int sum = 0;
		int res = nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			res = max(res, sum);
			sum = max(0, sum);
		}
		return res;
	}
};

class Solution {
public:
	/**
	 * @param nums: A list of integers
	 * @return: An integer indicate the sum of max subarray
	 */
	int maxSubArray(vector<int>& nums) {
		// write your code here
		if (nums.size() == 0) return 0;
		vector<int> presum(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); i++) presum[i + 1] = presum[i] + nums[i];
		int max_sum = nums[0];
		int g_low = INT_MAX;
		for (int i = 0; i < presum.size(); i++)
		{
			max_sum = max(max_sum, presum[i] - g_low);
			g_low = min(g_low, presum[i]);
		}
		return max_sum;
	}
};