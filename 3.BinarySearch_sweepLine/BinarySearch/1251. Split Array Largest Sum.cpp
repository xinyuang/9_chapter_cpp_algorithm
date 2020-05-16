1251. Split Array Largest Sum


class Solution {
public:
	/**
	 * @param nums: a list of integers
	 * @param m: an integer
	 * @return: return a integer
	 */
	int splitArray(vector<int>& nums, int m) {
		// write your code here
		long lower = *max_element(begin(nums), end(nums));
		long upper = accumulate(begin(nums), end(nums), 0L) + 1;
		while (lower + 1 < upper)
		{
			long mid = (upper - lower) / 2 + lower;
			if (max_group(nums, mid) > m)
			{
				lower = mid;
			}
			else upper = mid;
		}
		if (max_group(nums, lower) == m) return lower;
		return upper;
	}

	int max_group(vector<int>& nums, long target)
	{
		int group = 1;
		long sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (sum + nums[i] > target)
			{
				sum = nums[i];
				group++;
			}
			else sum += nums[i];
		}
		return group;
	}
};