//5. Kth Largest Element
//1. quickSelect(worst O(n2) avg O(n))
//2. large - start + 1 == n

class Solution {
public:
	/**
	 * @param n: An integer
	 * @param nums: An array
	 * @return: the Kth largest element
	 */
	int kthLargestElement(int n, vector<int>& nums) {
		// write your code here
		int res = findKth(n, nums, 0, nums.size() - 1);
		return res;
	}

	int findKth(int k, vector<int>& nums, int start, int end)
	{
		if (start >= end) return nums[start];
		int large = start, largeSeeker = start + 1;
		while (largeSeeker <= end)
		{
			if (nums[largeSeeker] > nums[start])
			{
				large++;
				swap(nums[large], nums[largeSeeker]);
			}
			largeSeeker++;
		}
		swap(nums[large], nums[start]);
		if (large - start + 1 == k) return nums[large];
		else if (large - start + 1 < k) return findKth(k - (large - start + 1), nums, large + 1, end);
		else return findKth(k, nums, start, large - 1);
	}
};