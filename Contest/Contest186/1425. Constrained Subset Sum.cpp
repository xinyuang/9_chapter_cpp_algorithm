//1425. Constrained Subset Sum
//1. dp[i] = max(dp[i], max(0, dp[i - k] ... dp[i - 1]))
//2. use multiset<int> or monoqueue to store sliding window[i - k] ...[i - 1], get window max

class Solution {
public:
	int constrainedSubsetSum(vector<int>& nums, int k) {
		multiset<int> st;
		st.insert(INT_MIN);
		vector<int> dp(nums.size(), 0);
		int max_res = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			dp[i] = nums[i] + max(0, *st.rbegin());
			st.insert(dp[i]);
			if (st.size() > k && i - k >= 0) st.erase(st.find(dp[i - k]));
			max_res = max(max_res, dp[i]);
		}
		return max_res;
	}
};