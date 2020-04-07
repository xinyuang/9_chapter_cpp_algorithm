//1406. Stone Game III
//dp[m] = Xm - Ym, dp[n] = 0, dp[0] = X0 - Y0 >= 0
//dp[i] = max(vi - dp[i + 1], vi + v(i + 1) - dp[i + 2], vi + v(i + 1) + v(i + 2) - dp[i + 3])

class Solution {
public:
	string stoneGameIII(vector<int>& stoneValue) {
		vector<int> dp(stoneValue.size() + 1, 0);
		dp[stoneValue.size() - 1] = stoneValue.back();
		if (stoneValue.size() == 1)
		{
			if (dp[0] > 0) return "Alice";
			if (dp[0] < 0) return "Bob";
			return "Tie";
		}
		int n = stoneValue.size() - 2;
		dp[stoneValue.size() - 2] = max(stoneValue[n] - dp[n + 1], stoneValue[n] + stoneValue[n + 1] - dp[n + 2]);
		for (int i = stoneValue.size() - 3; i >= 0; i--)
		{
			dp[i] = max(max(stoneValue[i] - dp[i + 1], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]),
				stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
		}
		if (dp[0] > 0) return "Alice";
		if (dp[0] < 0) return "Bob";
		return "Tie";
	}
};