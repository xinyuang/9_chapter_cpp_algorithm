// Card Game II
// no duplicate card allowed
// 01 complete
class Solution {
public:
	/**
	 * @param cost: costs of all cards
	 * @param damage: damage of all cards
	 * @param totalMoney: total of money
	 * @param totalDamage: the damage you need to inflict
	 * @return: Determine if you can win the game
	 */
	bool cardGame(vector<int>& cost, vector<int>& damage, int totalMoney, int totalDamage) {
		// Write your code here
		vector<int> dp(totalMoney + 1, 0);
		for (int i = 0; i < cost.size(); i++)
		{
			for (int j = totalMoney; j >= cost[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - cost[i]] + damage[i]);
			}
		}
		return dp.back() >= totalDamage;
	}
};