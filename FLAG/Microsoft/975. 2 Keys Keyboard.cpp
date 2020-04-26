//975. 2 Keys Keyboard
//[1 1 1 1 1]                      5
//[1 1 1 1 1] [1 1 1 1 1]          7 = 5 + (10/5)

class Solution {
public:
	/**
	 * @param n: The number of 'A'
	 * @return: the minimum number of steps to get n 'A'
	 */
	int minSteps(int n) {
		// Write your code here
		vector<int> dp(n + 1, 0xf3f3f3);
		dp[0] = 0; dp[1] = 0;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
			{
				if (i % j == 0)
				{
					dp[i] = min(dp[j] + i / j, dp[i]);
				}
			}
		}
		return dp.back();
	}
};