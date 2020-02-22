//633. Find the Duplicate Number

//1. fast = nums[nums[0]], slow = nums[0]
//2. while (fast != slow) fast = nums[nums[fast]], slow = nums[slow]
//3. fast = 0, while (fast != slow) fast = nums[fast], slow = nums[slow]

class Solution {
public:
	/**
	 * @param nums: an array containing n + 1 integers which is between 1 and n
	 * @return: the duplicate one
	 */
	int findDuplicate(vector<int>& nums) {
		// write your code here
		if (nums.size() == 0) return -1;
		int fast = nums[nums[0]], slow = nums[0];
		while (fast != slow)
		{
			fast = nums[nums[fast]];
			slow = nums[slow];
		}
		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return fast;
	}
};


//1. binary search range(1, n)
//2. if (find(mid, nums)) right = mid, else left = mid
//3. find(mid, nums) return count > mid, where count is element #   <= mid


class Solution {
public:
	/**
	 * @param nums: an array containing n + 1 integers which is between 1 and n
	 * @return: the duplicate one
	 */
	int findDuplicate(vector<int>& nums) {
		// write your code here
		int left = 1, right = nums.size();
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (find(mid, nums)) right = mid;
			else left = mid;
		}
		if (find(left, nums)) return left;
		return right;
	}

	bool find(int target, vector<int>& nums)
	{
		int count = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= target) count++;
		}
		return count > target;
	}
};