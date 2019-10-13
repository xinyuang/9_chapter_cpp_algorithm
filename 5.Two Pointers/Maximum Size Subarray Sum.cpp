// Maximum Size Subarray Sum
// presum
// unordered_map record current idx
// res = max(res,i - mp[presum[i] - k])
class Solution {
public:
	int maxSubArrayLen(vector<int> nums, int k) {
		// write your solution here
		if (nums.size() == 0) return 0;
		vector<int> presum(nums.size() + 1, 0);
		presum[0] = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			presum[i + 1] = presum[i] + nums[i];
		}
		unordered_map<int, int> mp;
		int res = 0;
		for (int i = 0; i < presum.size(); i++)
		{
			if (mp.count(presum[i] - k))
			{
				if (res < i - mp[presum[i] - k]) res = i - mp[presum[i] - k];
			}
			if (!mp.count(presum[i])) mp[presum[i]] = i;
		}
		return res;
	}
};