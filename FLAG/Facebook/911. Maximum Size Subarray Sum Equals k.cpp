//911. Maximum Size Subarray Sum Equals k
//1. presum(nums.size() + 1, 0), unordered_map store first presum idx
//2. longest = max(longest, i - mp[presum[i] - k])

class Solution {
public:
	/**
	 * @param nums: an array
	 * @param k: a target value
	 * @return: the maximum length of a subarray that sums to k
	 */
	int maxSubArrayLen(vector<int>& nums, int k) {
		// Write your code here
		vector<int> presum(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); i++) presum[i + 1] = presum[i] + nums[i];
		unordered_map<int, int> mp;
		mp[0] = 0;
		int res = 0;
		for (int i = 1; i < presum.size(); i++)
		{
			if (mp.count(presum[i] - k))
			{
				res = max(res, i - mp[presum[i] - k]);
			}
			if (!mp.count(presum[i])) mp[presum[i]] = i;
		}
		return res;
	}
};