// Median of K sorted Arrays
// find Kth  ( k == n/2 )
// find lower upper bound,
// int count = findLE(nums,tar)  count the number less or equal to target (num[mid]) 
// findK(vector<int> num, int tar) count the number less or equal to target
class Solution {
public:
	/**
	 * @param nums: the given k sorted arrays
	 * @return: the median of the given k sorted arrays
	 */
	double findMedian(vector<vector<int>>& nums) {
		// write your code here
		if (nums.size() == 0) return 0;
		int n = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			n += nums[i].size();
		}
		if (n == 0) return 0;
		if (n % 2 == 0) return (findKth(nums, n / 2 + 1) - findKth(nums, n / 2)) / 2.0 + findKth(nums, n / 2);
		return findKth(nums, n / 2 + 1);
	}
	int findKth(vector<vector<int>>& nums, int k)
	{
		int lower = INT_MAX;
		int upper = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i].size() == 0) continue;
			lower = min(lower, nums[i][0]);
			upper = max(upper, nums[i].back());
		}
		while (lower + 1 < upper)
		{
			int mid = (upper - lower) / 2 + lower;
			int count = findLE(nums, mid);
			if (count < k) lower = mid;
			else upper = mid;
		}
		if (findLE(nums, lower) >= k) return lower;
		return upper;
	}

	int findLE(vector<vector<int>>& nums, int target)
	{
		int count = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			count += findK(nums[i], target);
		}
		return count;
	}

	int findK(vector<int>& num, int target)
	{
		if (num.size() == 0) return 0;
		int left = 0;
		int right = num.size() - 1;
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (num[mid] <= target) left = mid;
			else right = mid;
		}
		if (num[left] > target) return left;
		if (num[right] > target) return right;
		return num.size();
	}
};