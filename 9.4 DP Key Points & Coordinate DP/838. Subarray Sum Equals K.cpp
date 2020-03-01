//838. Subarray Sum Equals K
//1. dp memo, use unordered_map to store state

class Solution {
public:
	/**
	 * @param nums: a list of integer
	 * @param k: an integer
	 * @return: return an integer, denote the number of continuous subarrays whose sum equals to k
	 */
	int subarraySumEqualsK(vector<int>& nums, int k) {
		// write your code here
		int presum = 0;
		unordered_map<int, int> mp;
		mp[0] = 1;
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			presum += nums[i];
			if (mp.count(presum - k))
			{
				res += mp[presum - k];
			}
			mp[presum]++;
		}
		return res;
	}
};