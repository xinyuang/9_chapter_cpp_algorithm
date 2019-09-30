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
		int low = nums[0];
		int high = INT_MIN;
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