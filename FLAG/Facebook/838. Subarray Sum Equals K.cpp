//838. Subarray Sum Equals K
//presum[i] - presum[j] = k  => number of (presum[i] - k)

class Solution {
public:
	/**
	 * @param nums: a list of integer
	 * @param k: an integer
	 * @return: return an integer, denote the number of continuous subarrays whose sum equals to k
	 */
	int subarraySumEqualsK(vector<int>& nums, int k) {
		// write your code here
		vector<int> presum(nums.size() + 1, 0);
		for (int i = 1; i <= nums.size(); i++)
		{
			presum[i] = presum[i - 1] + nums[i - 1];
		}
		unordered_map<int, int> mp;
		int res = 0;
		for (int i = 0; i < presum.size(); i++)
		{
			if (mp.count(presum[i] - k)) res += mp[presum[i] - k];
			mp[presum[i]]++;
		}
		return res;
	}
};