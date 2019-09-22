class Solution {
public:
	/**
	 * @param A: An array of non-negative integers
	 * @return: The maximum amount of money you can rob tonight
	 */
	long long houseRobber(vector<int>& A) {
		// write your code here
		long last = A[0], last_two = 0;
		long now = 0;
		for (int i = 1; i < A.size(); i++)
		{
			now = max(last, last_two + A[i]);
			last_two = last;
			last = now;

		}
		return max(now, last);
	}
};

// house robber II (with circle)
class Solution {
public:
	/**
	 * @param nums: An array of non-negative integers.
	 * @return: The maximum amount of money you can rob tonight
	 */
	int houseRobber2(vector<int>& nums) {
		// write your code here
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		vector<int> dp(nums.size(), 0);
		dp[0] = 0;
		dp[1] = nums[0];
		for (int i = 1; i < nums.size() - 1; i++)
		{
			dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
		}
		int ans = dp[nums.size() - 1];
		dp[0] = 0;
		dp[1] = nums[1];
		for (int i = 2; i < nums.size(); i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		return max(ans, dp[nums.size() - 1]);
	}
};