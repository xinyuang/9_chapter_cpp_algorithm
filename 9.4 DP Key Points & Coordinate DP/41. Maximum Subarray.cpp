// maximum subarray

class Solution {
public:
	/**
	 * @param nums: A list of integers
	 * @return: An integer indicate the sum of max subarray
	 */
	int maxSubArray(vector<int>& nums) {
		// write your code here
		int low = 0;   // first lowest is empty
		int presum = 0;
		int diff = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			presum += nums[i];
			diff = max(diff, presum - low);
			low = min(low, presum);
		}
		return diff;
	}
};

// record the idx of max sum subarray
class Solution {
public:
	vector<int> largestSum(vector<int> array) {
		// write your solution here
		vector<int> presum(array.size() + 1, 0);
		for (int i = 0; i < array.size(); i++)
		{
			presum[i + 1] = presum[i] + array[i];
		}
		int g_min = 0;
		int left = 0;
		int diff = INT_MIN;
		vector<int> res(3, 0);
		for (int i = 1; i < presum.size(); i++)
		{
			int cur_diff = presum[i] - g_min;
			if (cur_diff > diff)
			{
				diff = cur_diff;
				res[0] = diff;
				res[1] = left;
				res[2] = i - 1;
			}
			if (g_min > presum[i])
			{
				left = i;
				g_min = presum[i];
			}
		}
		return res;
	}
};

class Solution {
public:
	/**
	 * @param nums: A list of integers
	 * @return: An integer indicate the sum of max subarray
	 */
	int maxSubArray(vector<int>& nums) {
		// write your code here
		if (nums.size() == 0) return 0;
		vector<int> presum(nums.size() + 1, 0);
		int low = nums[0];
		int high = INT_MIN;
		int sum = 0;
		int res = nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			res = max(res, sum);
			sum = max(0, sum);
		}
		return res;
	}
};