//1251. Split Array Largest Sum
//1. binary search if we can find the tar = max(nums[i])
//2. if we can find, then tar can be smaller
//3. in findMax() put ele as much as possible in one group, check group <= m


class Solution {
public:
	/**
	 * @param nums: a list of integers
	 * @param m: an integer
	 * @return: return a integer
	 */
	int splitArray(vector<int>& nums, int m) {
		// write your code here
		int min_v = 0;
		int max_v = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			min_v = max(min_v, nums[i]);
			max_v += nums[i];
		}
		while (min_v + 1 < max_v)
		{
			int mid = (max_v - min_v) / 2 + min_v;
			if (canFind(mid, nums, m)) max_v = mid;
			else min_v = mid;
		}
		if (canFind(min_v, nums, m)) return min_v;
		return max_v;
	}

	bool canFind(int tar, vector<int>& nums, int m)
	{
		int group = 1;
		int cur_sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (cur_sum + nums[i] <= tar)
			{
				cur_sum += nums[i];
			}
			else
			{
				cur_sum = nums[i];
				group++;
			}
		}
		return group <= m;
	}
};