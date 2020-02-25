//76. Longest Increasing Subsequence
//1. fake LIS
//2. find lower_bound(LIS.begin(), LIS.end(), n[i])
//3. if find, replace, otherwise push_back(n[i])

class Solution {
public:
	/**
	 * @param nums: An integer array
	 * @return: The length of LIS (longest increasing subsequence)
	 */
	int longestIncreasingSubsequence(vector<int>& nums) {
		// write your code here
		vector<int> dp(nums.size(), 1);
		int longest = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i; j >= 0; j--)
			{
				if (nums[i] > nums[j])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			if (longest < dp[i]) longest = dp[i];
		}
		return longest;
	}
};

class Solution {
public:
	/**
	 * @param nums: An integer array
	 * @return: The length of LIS (longest increasing subsequence)
	 */
	int longestIncreasingSubsequence(vector<int>& nums) {
		// write your code here
		vector<int> LIS;
		for (int i = 0; i < nums.size(); i++)
		{
			vector<int>::iterator it = lower_bound(LIS.begin(), LIS.end(), nums[i]);
			if (it == LIS.end()) LIS.push_back(nums[i]);
			else
			{
				*it = nums[i];
			}
		}
		return LIS.size();
	}
};