//  Climbing Stairs
//  Fibonacci sequence
class Solution {
public:
	/**
	 * @param n: An integer
	 * @return: An integer
	 */
	 //  0,1,2,3,4,5  n = 5
	 //  1 1 
	 //      2 
	 //        3
	 //          5
	 //            8

	int climbStairs(int n) {
		// write your code here
		if (n == 0) return 0;
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= 2; j++)
			{
				dp[i] = dp[i - j] + dp[i];
			}
		}
		return dp.back();
	}
};