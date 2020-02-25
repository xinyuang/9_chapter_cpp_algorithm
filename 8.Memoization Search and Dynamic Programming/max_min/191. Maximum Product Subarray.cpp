//191. Maximum Product Subarray
//1. pos = max(max(pos * nums[i], neg * nums[i]), nums[i]);
//2. neg = min(min(last_pos * nums[i], neg * nums[i]), nums[i]);
//3. res = max(res, pos);

class Solution {
public:
	/**
	 * @param nums: An array of integers
	 * @return: An integer
	 */
	int maxProduct(vector<int>& nums) {
		// write your code here
		if (nums.size() == 0) return 0;
		int pos = nums[0], neg = nums[0];
		int res = pos;
		for (int i = 1; i < nums.size(); i++)
		{
			int last_pos = pos;
			pos = max(max(pos * nums[i], neg * nums[i]), nums[i]);
			neg = min(min(last_pos * nums[i], neg * nums[i]), nums[i]);
			res = max(pos, res);
		}
		return res;
	}
};