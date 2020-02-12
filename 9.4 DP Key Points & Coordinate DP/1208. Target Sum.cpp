//1208. Target Sum
//You are given a list of non - negative integers, a1, a2, ..., an, and a target, S.
//Now you have 2 symbols + and -.For each integer, you should choose one from + and -as its new symbol.
//Find out how many ways to assign symbols to make sum of integers equal to target S.

// DP
// nums [1,2,5,2,6]  range [-sum,sum]  => [0,2*sum]
// for(int i = 0; i < nums.size(); i++)        dp[i][j] += dp[i-1][j +/- nums[i]]
class Solution {
public:
	/**
	 * @param nums: the given array
	 * @param s: the given target
	 * @return: the number of ways to assign symbols to make sum of integers equal to target S
	 */
	int findTargetSumWays(vector<int>& nums, int s) {
		// Write your code here
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
		}
		if (sum < abs(s)) return 0;
		vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, 0));
		if (nums[0] == 0) dp[0][sum] = 2;
		else {
			dp[0][sum - nums[0]] = 1;
			dp[0][sum + nums[0]] = 1;
		}
		for (int i = 1; i < nums.size(); i++)
		{
			for (int j = 0; j <= 2 * sum; j++)
			{
				if (j + nums[i] <= 2 * sum) dp[i][j] += dp[i - 1][j + nums[i]];
				if (j - nums[i] >= 0) dp[i][j] += dp[i - 1][j - nums[i]];
			}
		}
		return dp[nums.size() - 1][sum + s];
	}
};



// backtrack enum all the solutions
class Solution {
public:
	/**
	 * @param nums: the given array
	 * @param s: the given target
	 * @return: the number of ways to assign symbols to make sum of integers equal to target S
	 */
	int findTargetSumWays(vector<int>& nums, int s) {
		// Write your code here
		int res = 0;
		int symbol = 0;
		findWays(res, symbol, s, nums);
		return res;
	}

	void findWays(int& res, int& symbol, int target, vector<int>& nums)
	{
		if (target == 0 && symbol == nums.size())
		{
			res++;
			return;
		}
		if (symbol == nums.size()) return;
		for (int i = 0; i < 2; i++)
		{
			int next = nums[symbol] * fac[i];
			symbol++;
			findWays(res, symbol, target - next, nums);
			symbol--;
		}
	}

private:
	int fac[2] = { 1,-1 };
};