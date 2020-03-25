//196. Missing Number
//swap until nums[i] == i

class Solution {
public:
	/**
	 * @param nums: An array of integers
	 * @return: An integer
	 */
	int findMissing(vector<int>& nums) {
		// write your code here

		for (int i = 0; i < nums.size(); i++)
		{
			while (nums[i] != i && nums[i] < nums.size()) swap(nums[i], nums[nums[i]]);
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != i) return i;
		}
		return nums.size();
	}
};