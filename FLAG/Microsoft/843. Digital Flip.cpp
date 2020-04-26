//843. Digital Flip
//for each position i, mininum operation is #left zero + #right one

class Solution {
public:
	/**
	 * @param nums: the array
	 * @return: the minimum times to flip digit
	 */
	int flipDigit(vector<int>& nums) {
		// Write your code here
		vector<int> left_zero(nums.size(), 0);
		vector<int> right_one(nums.size(), 0);
		for (int i = nums.size() - 2; i >= 0; i--)
		{
			right_one[i] = right_one[i + 1] + nums[i + 1];
		}
		int min_opt = nums.size();
		for (int i = 0; i < nums.size(); i++)
		{
			if (i != 0) left_zero[i] = left_zero[i - 1] + (1 - nums[i - 1]);
			min_opt = min(min_opt, right_one[i] + left_zero[i]);
		}
		return min_opt;
	}
};