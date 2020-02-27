//393. Best Time to Buy and Sell Stock IV
//if K > prices.size()/2, inf
//sell[j] = max(sell[j], hold[j] + prices[i])
//hold[j] = max(hold[j], sell[j - 1] - prices[i])



class Solution {
public:
	/**
	 * @param K: An integer
	 * @param prices: An integer array
	 * @return: Maximum profit
	 */
	int maxProfit(int K, vector<int>& prices) {
		// write your code here
		if (K > prices.size() / 2) {
			int profit = 0;
			for (int i = 1; i < prices.size(); i++)
			{
				profit += max(0, prices[i] - prices[i - 1]);
			}
			return profit;
		}
		vector<int> sell(K, 0);
		vector<int> hold(K, INT_MIN);
		for (int i = 0; i < prices.size(); i++)
		{
			sell[0] = max(sell[0], hold[0] + prices[i]);
			hold[0] = max(hold[0], -prices[i]);
			for (int k = 1; k < K; k++)
			{
				sell[k] = max(sell[k], hold[k] + prices[i]);
				hold[k] = max(hold[k], sell[k - 1] - prices[i]);
			}
		}
		return sell.back();
	}
};