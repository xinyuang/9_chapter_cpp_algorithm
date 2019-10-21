// Cutting a Rod (complete backpack)
// length [0,1,2,3]  ttl len m = 5
// price  [0,1,3,6]
// cut to pieces to get the max value
//       0,1,2,3,4,5
//    0  0,0,0,0,0,0
//    1  0,1,2,3,4,5
//    2  0,1,3,4,5,6
//    3
class Solution {
public:
	/**
	 * @param prices: the prices
	 * @param n: the length of rod
	 * @return: the max value
	 */
	int cutting(vector<int>& prices, int n) {
		// Write your code here
		vector<int> dp(n + 1, 0);
		for (int i = 0; i < prices.size(); i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (j - (i + 1) < 0) dp[j] = dp[j];
				else dp[j] = max(dp[j], dp[j - (i + 1)] + prices[i]);
			}
		}
		return dp.back();
	}
};