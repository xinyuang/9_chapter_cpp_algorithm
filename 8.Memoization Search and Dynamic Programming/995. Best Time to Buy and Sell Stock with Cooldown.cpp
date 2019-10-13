// Buy stock

// Only once
// global max - global min (min is before max)
class Solution {
public:
	/**
	 * @param prices: Given an integer array
	 * @return: Maximum profit
	 */
	int maxProfit(vector<int>& prices) {
		// write your code here
		int g_min = INT_MAX;
		int profit = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			profit = max(profit, prices[i] - g_min);
			g_min = min(g_min, prices[i]);
		}
		return profit;
	}
};

// Only once
// state transfer
// hold = max(hold, -array[i]);
class Solution {
public:
	int maxProfit(vector<int> array) {
		// write your solution here
		//   (hold) -> (sell)
		//          <- 
		if (array.size() == 0) return 0;
		int sell = 0;
		int hold = INT_MIN;
		for (int i = 0; i < array.size(); i++)
		{
			sell = max(sell, array[i] + hold);
			hold = max(hold, -array[i]);  // only once start from 0
		}
		return sell;
	}
};


// can deal infinite times
// hold = max(hold, sell - prices[i]);
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) return 0;
		int sell = 0;
		int hold = INT_MIN;
		for (int i = 0; i < prices.size(); i++)
		{
			sell = max(sell, prices[i] + hold);
			hold = max(hold, sell - prices[i]);  // infinite times start from last sell
		}
		return sell;
	}
};

// buy twice
class Solution {
public:
	/**
	 * @param prices: Given an integer array
	 * @return: Maximum profit
	 */
	int maxProfit(vector<int>& prices) {
		// write your code here
		int firstHold = INT_MIN, firstSell = 0;
		int secondHold = INT_MIN, secondSell = 0;
		for (auto price : prices)
		{
			secondSell = max(secondSell, secondHold + price);
			secondHold = max(secondHold, firstSell - price);
			firstSell = max(firstSell, firstHold + price);
			firstHold = max(firstHold, -price);
		}
		return secondSell;
	}
};

// with cool down
class Solution {
public:
	/**
	 * @param prices: a list of integers
	 * @return: return a integer
	 */
	int maxProfit(vector<int>& prices) {
		// write your code here
		vector<int> buy(prices.size() + 1, INT_MIN);
		vector<int> cool(prices.size() + 1, 0);
		vector<int> sell(prices.size() + 1, 0);
		for (int i = 0; i < prices.size(); i++)
		{
			sell[i + 1] = max(sell[i], buy[i] + prices[i]);
			cool[i + 1] = sell[i];
			buy[i + 1] = max(buy[i], cool[i] - prices[i]);
		}
		return sell.back();
	}
};

// can buy K times at most
class Solution {
public:
	/**
	 * @param K: An integer
	 * @param prices: An integer array
	 * @return: Maximum profit
	 */
	int maxProfit(int K, vector<int>& prices) {
		// write your code here
		if (prices.size() / 2 <= K)
		{
			int res = 0;
			int last = INT_MIN;
			for (auto price : prices)
			{
				res += max(price - last, 0);
				last = price;
			}
			return res;
		}
		vector<int> hold(K + 1, INT_MIN);
		vector<int> sell(K + 1, 0);
		for (auto price : prices)
		{
			for (int i = K; i >= 1; i--)
			{
				sell[i] = max(sell[i], hold[i] + price);
				hold[i] = max(hold[i], sell[i - 1] - price);
			}
		}
		return sell[K];
	}
};