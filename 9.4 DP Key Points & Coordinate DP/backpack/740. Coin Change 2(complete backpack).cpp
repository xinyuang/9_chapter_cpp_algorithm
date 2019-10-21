// coin change 2
// compute the number of combinations that make up that amount
// [1,2,1] and [1,1,2] are same solution
class Solution {
public:
	/**
	 * @param amount: a total amount of money amount
	 * @param coins: the denomination of each coin
	 * @return: the number of combinations that make up the amount
	 */
	int change(int amount, vector<int>& coins) {
		// write your code here
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		for (int j = 0; j < coins.size(); j++)

		{
			for (int i = coins[j]; i <= amount; i++) 
													// allow duplication use normal order
													//  no duplication use reverse order
			{
				dp[i] += dp[i - coins[j]];
			}
		}
		return dp[amount];
	}
};