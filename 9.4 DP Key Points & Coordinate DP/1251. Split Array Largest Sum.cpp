// Split Array Largest Sum
//    [2,4,6,3,1,4,9]
//    [2,4,6,3]  | [1,4,9]
//    min ( res, max( SearchLargest([2,4,6,3])  |  sum([1,4,9]) ))
//    memo[j][i] nums[:i] split into j group,  max sum
//    search(nums, end, m, presum, memo)
class Solution {
public:
	/**
	 * @param nums: a list of integers
	 * @param m: an integer
	 * @return: return a integer
	 */
	int splitArray(vector<int>& nums, int m) {
		// write your code here
		if (nums.size() < m || nums.size() == 0) return INT_MAX;
		vector<int> presum(nums.size(), 0);
		presum[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			presum[i] = presum[i - 1] + nums[i];
		}
		// max(search(k,m-1),sum(k,end))
		vector<vector<int>> memo(m + 1, vector<int>(nums.size(), -1));
		int res = search(nums, nums.size() - 1, m, presum, memo);
		return res;
	}

	int search(vector<int>& nums, int end, int m, vector<int>& presum, vector<vector<int>>& memo)
	{
		if (m == 1) return presum[end];
		if (m > end + 1) return INT_MAX;
		if (memo[m][end] != -1) return memo[m][end];
		int res = INT_MAX;
		for (int i = 0; i < end; i++)
		{
			res = min(res, max(search(nums, i, m - 1, presum, memo), presum[end] - presum[i]));
		}
		memo[m][end] = res;
		return res;
	}
};

class Solution {
public:
	/**
	 * @param nums: a list of integers
	 * @param m: an integer
	 * @return: return a integer
	 */
	int splitArray(vector<int>& nums, int m) {
		// write your code here
		vector<int> presum(nums.size(), 0);
		presum[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			presum[i] = presum[i - 1] + nums[i];
		}
		vector<vector<int>> dp(m + 1, vector<int>(nums.size(), INT_MAX));
		for (int i = 0; i < nums.size(); i++) dp[1][i] = presum[i];
		for (int i = 2; i <= m; i++)
		{
			for (int j = i - 1; j < nums.size(); j++)
			{
				for (int k = 0; k < j; k++)
				{
					dp[i][j] = min(dp[i][j], max(dp[i - 1][k], presum[j] - presum[k]));
				}
			}
		}
		return dp[m][nums.size() - 1];
	}
};


class Solution {
public:
	/**
	 * @param nums: a list of integers
	 * @param m: an integer
	 * @return: return a integer
	 */
	int splitArray(vector<int>& nums, int m) {
		// write your code here
		long lower = *max_element(begin(nums), end(nums));
		long upper = accumulate(begin(nums), end(nums), 0L) + 1;
		while (lower + 1 < upper)
		{
			long mid = (upper - lower) / 2 + lower;
			if (max_group(nums, mid) > m)
			{
				lower = mid;
			}
			else upper = mid;
		}
		if (max_group(nums, lower) == m) return lower;
		return upper;
	}

	int max_group(vector<int>& nums, long target)
	{
		int group = 1;
		long sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (sum + nums[i] > target)
			{
				sum = nums[i];
				group++;
			}
			else sum += nums[i];
		}
		return group;
	}
};