//533. Two Sum - Closest to target
//1. sort, two pointer, if small left++, else right--, update smallest_diff

class Solution {
public:
	/**
	 * @param nums: an integer array
	 * @param target: An integer
	 * @return: the difference between the sum and the target
	 */
	int twoSumClosest(vector<int>& nums, int target) {
		// write your code here
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.size() - 1;
		int min_diff = INT_MAX;
		while (left < right)
		{
			min_diff = min(min_diff, abs(target - nums[left] - nums[right]));
			if (left < right && nums[left] + nums[right] < target)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
		return min_diff;
	}
};


class Solution {
public:
	/**
	 * @param nums: an integer array
	 * @param target: An integer
	 * @return: the difference between the sum and the target
	 */
	int twoSumClosest(vector<int>& nums, int target) {
		// write your code here
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.size() - 1;
		int res = INT_MAX;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			int sub_tar = target - nums[i];
			int closest = findClosest(nums, sub_tar, i + 1);
			res = min(res, abs(target - closest - nums[i]));
		}
		return res;
	}

	int findClosest(vector<int>& nums, int target, int start)
	{
		int left = start, right = nums.size() - 1;
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (nums[mid] < target) left = mid;
			else right = mid;
		}
		return abs(target - nums[left]) < abs(target - nums[right]) ? nums[left] : nums[right];
	}
};