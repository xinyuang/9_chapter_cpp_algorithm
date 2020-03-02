//406. Minimum Size Subarray Sum
//1. presum  for loop i cur_sum = presum[i] - presum[left]
//2. while loop left++ get min_len = min(min_len, i - left)

class Solution {
public:
	/**
	 * @param nums: an array of integers
	 * @param s: An integer
	 * @return: an integer representing the minimum size of subarray
	 */
	int minimumSize(vector<int>& nums, int s) {
		// write your code here
		vector<int> presum(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); i++) presum[i + 1] = presum[i] + nums[i];
		if (s > presum.back()) return -1;
		int min_len = INT_MAX;
		int ptr = 0;
		for (int i = 1; i < presum.size(); i++)
		{
			while (ptr < i && presum[i] - presum[ptr] >= s) ptr++;
			if (ptr == 0 && presum[i] - presum[ptr] < s) continue;
			int cur_len = i - ptr + 1;
			min_len = min(min_len, cur_len);
		}
		return min_len;
	}
};