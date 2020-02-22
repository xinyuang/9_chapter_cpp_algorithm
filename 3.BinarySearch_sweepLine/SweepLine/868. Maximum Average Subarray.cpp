//868. Maximum Average Subarray
//sweep line sliding window

class Solution {
public:
	/**
	 * @param nums: an array
	 * @param k: an integer
	 * @return: the maximum average value
	 */
	double findMaxAverage(vector<int>& nums, int k) {
		// Write your code here
		double sum = 0;
		for (int i = 0; i < k; i++) sum += nums[i];
		double max_sum = sum;
		for (int i = k; i < nums.size(); i++)
		{
			sum -= nums[i - k];
			sum += nums[i];
			max_sum = max(sum, max_sum);
		}
		return max_sum / k;
	}
};