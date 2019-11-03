// next Permutation
//  xxx24321  find the first (non-increasing) small one, swap with the second small one
class Solution {
public:
	/**
	 * @param nums: An array of integers
	 * @return: nothing
	 */
	void nextPermutation(vector<int>& nums) {
		// write your code here
		if (nums.size() < 2) return;
		int end = nums.size() - 1;
		int start = end - 1;
		while (start >= 0)
		{
			if (nums[start] < nums[end]) break;
			end--;
			start--;
		}
		if (start == -1) {
			std::reverse(nums.begin(), nums.end());
			return;
		}
		int second = nums.size() - 1;
		while (second > start)
		{
			if (nums[second] > nums[start]) break;
			second--;
		}
		swap(nums[start], nums[second]);
		reverse(start + 1, nums.size() - 1, nums);
	}

	void reverse(int l, int r, vector<int>& nums)
	{
		while (l < r)
		{
			swap(nums[l], nums[r]);
			l++; r--;
		}

	}
};