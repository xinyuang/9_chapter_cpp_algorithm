//402. Continuous Subarray Sum
//1. presum(nums.size() + 1, 0)
//2. low = min(low, presum[i - 1]), low_idx = i - 1;
//3. diff = max(diff, presum[i] - low)  res = [low_idx, i]

class Solution {
public:
	/*
	 * @param A: An integer array
	 * @return: A list of integers includes the index of the first number and the index of the last number
	 */
	vector<int> continuousSubarraySum(vector<int>& A) {
		// write your code here
		vector<int> presum(A.size() + 1, 0);
		for (int i = 0; i < A.size(); i++) presum[i + 1] = presum[i] + A[i];
		int low = presum[0], low_idx = 0;
		int max_sum = INT_MIN;
		vector<int> res(2, 0);
		for (int i = 1; i < presum.size(); i++)
		{
			if (max_sum < presum[i] - low)
			{
				max_sum = presum[i] - low;
				res[0] = low_idx;
				res[1] = i - 1;
			}
			if (presum[i] < low)
			{
				low = presum[i];
				low_idx = i;
			}
		}
		return res;
	}
};