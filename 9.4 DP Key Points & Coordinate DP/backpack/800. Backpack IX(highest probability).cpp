// 800. Backpack IX

// DP
class Solution {
public:
	/**
	 * @param n: Your money
	 * @param prices: Cost of each university application
	 * @param probability: Probability of getting the University's offer
	 * @return: the  highest probability
	 */
	double backpackIX(int n, vector<int>& prices, vector<double>& probability) {
		// write your code here
		vector<double> dp(n + 1, 1);
		dp[0] = 1;
		for (int i = 0; i < prices.size(); i++)
		{
			for (int j = n; j >= prices[i]; j--)
			{
				double candidate = dp[j - prices[i]] * (1 - probability[i]);
				dp[j] = min(dp[j], candidate);
			}
		}
		return 1 - dp[n];
	}
};

// backtrack Time Limit Exceeded
class Solution {
public:
	/**
	 * @param n: Your money
	 * @param prices: Cost of each university application
	 * @param probability: Probability of getting the University's offer
	 * @return: the  highest probability
	 */

	 // p = 1 - (1-P1)(1-p2)
	double backpackIX(int n, vector<int>& prices, vector<double>& probability) {
		// write your code here
		vector<int> path;
		double pos = 0;
		find(pos, path, 0, 0, n, prices, probability);
		return pos;
	}

	void find(double& pos, vector<int>& path, int start, int sum, int n, vector<int>& prices, vector<double>& probability)
	{
		if (sum > n) return;
		double cur_pos = 1;
		for (int idx : path)
		{
			cur_pos *= (1 - probability[idx]);
		}
		cur_pos = 1 - cur_pos;
		if (cur_pos > pos) pos = cur_pos;
		for (int i = start; i < prices.size(); i++)
		{
			path.push_back(i);
			sum += prices[i];
			find(pos, path, i + 1, sum, n, prices, probability);
			path.pop_back();
			sum -= prices[i];
		}
	}
};