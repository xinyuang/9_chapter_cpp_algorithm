//403. Continuous Subarray Sum II
//in circular array, presum - min_presum is the max_sum
//
//1. presum(nums.size() + 1, 0)
//2. presum.back() - min(subarray sum) is circular max subarray sum
//3. when opposite empty, min(subarray sum) == presum.back() return line max subarray sum
//4. return max(max subarray sum, presum.back() - min subarray sum)

class Solution {
public:
	/*
	 * @param A: An integer array
	 * @return: A list of integers includes the index of the first number and the index of the last number
	 */
	vector<int> continuousSubarraySumII(vector<int>& A) {
		// write your code here
		vector<int> presum(A.size() + 1, 0);
		for (int i = 0; i < A.size(); i++) presum[i + 1] = presum[i] + A[i];
		int low = presum[0], low_idx = 0;
		int max_sum = INT_MIN;
		int high = presum[0], high_idx = 0;
		int min_sum = INT_MAX;
		vector<int> max_res(2, 0);
		vector<int> min_res(2, 0);
		for (int i = 1; i < presum.size(); i++)
		{
			if (max_sum < presum[i] - low)
			{
				max_sum = presum[i] - low;
				max_res[0] = low_idx;
				max_res[1] = i - 1;
			}
			if (low > presum[i])
			{
				low = presum[i];
				low_idx = i;
			}

			if (min_sum > presum[i] - high)
			{
				min_sum = presum[i] - high;
				min_res[0] = high_idx;
				min_res[1] = i - 1;
			}
			if (high < presum[i])
			{
				high = presum[i];
				high_idx = i;
			}
		}
		if (max_sum >= presum.back() - min_sum || min_sum == presum.back()) return max_res;
		return { min_res[1] + 1, min_res[0] - 1 };
	}
};