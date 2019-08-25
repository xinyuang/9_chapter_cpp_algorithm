class Solution {
public:
	/**
	 * @param prices: a list of integers
	 * @return: return a integer
	 */
	int maxProfit(vector<int>& prices) {
		// write your code here
		vector<int> buy(prices.size() + 1, INT_MIN);
		vector<int> sell(prices.size() + 1, 0);
		vector<int> cool(prices.size() + 1, 0);
		for (int i = 0; i < prices.size(); i++)
		{
			cool[i + 1] = max(sell[i], cool[i]);
			buy[i + 1] = max(buy[i], cool[i] - prices[i]);
			sell[i + 1] = buy[i] + prices[i];
		}
		return max(cool.back(), sell.back());
	}
};