//52. Next Permutation
//1. from right to left, find the first decreasing point A
//2. from right to left, find the first number B larger than A, swap
//3. reverse substr(A)

class Solution {
public:
	/**
	 * @param nums: A list of integers
	 * @return: A list of integers
	 */
	vector<int> nextPermutation(vector<int>& nums) {
		// write your code here
		int cur = nums.size() - 2;
		while (cur >= 0)
		{
			if (nums[cur] < nums[cur + 1]) break;
			cur--;
		}
		if (cur == -1)
		{
			reverse(nums.begin(), nums.end());
			return nums;
		}
		int small = cur;
		cur = nums.size() - 1;
		while (cur > small)
		{
			if (nums[cur] > nums[small])
			{
				swap(nums[cur], nums[small]);
				break;
			}
			cur--;
		}
		reverse_part(small + 1, nums);
		return nums;
	}

	void reverse_part(int start, vector<int>& nums)
	{
		int end = nums.size() - 1;
		while (start < end)
		{
			swap(nums[start], nums[end]);
			start++; end--;
		}
	}
};