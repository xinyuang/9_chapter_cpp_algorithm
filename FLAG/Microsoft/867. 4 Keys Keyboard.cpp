//867. 4 Keys Keyboard
//define dp[i] is max number of A can be generated using i step
//dp[i] = max(dp[i], dp[j] * (i - (j + 3) + 2))

class Solution {
public:
	/**
	 * @param N: an integer
	 * @return: return an integer
	 */
	int maxA(int N) {
		// write your code here
		vector<int> dp(N + 1, 0);
		dp[1] = 1; dp[2] = 2;
		int max_copy = 1;
		for (int i = 3; i <= N; i++)
		{
			dp[i] = dp[i - 1] + 1;
			for (int j = 1; j < i - 2; j++)
			{
				dp[i] = max(dp[i], dp[j] * (i - j - 1));
			}
		}
		return dp.back();
	}
};