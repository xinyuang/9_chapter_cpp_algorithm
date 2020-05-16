//516. Paint House II
//1. use priority_queue max_heap store idx, min_cost.top2
//2. go through current level, get current min cost, update max_heap


class com {
public:
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	}
};


class Solution {
public:
	/**
	 * @param costs: n x k cost matrix
	 * @return: an integer, the minimum cost to paint all houses
	 */
	int minCostII(vector<vector<int>>& costs) {
		// write your code here
		if (costs.size() == 0 || costs[0].size() < 2) return 0;
		vector<vector<int>> dp(costs.size() + 1, vector<int>(costs[0].size(), 0));
		vector<pair<int, int>> top2 = { {-1,0},{-1,0} };  // idx, min_cost
		priority_queue<pair<int, int>, vector<pair<int, int>>, com> max_heap;
		for (int i = 0; i < costs.size(); i++)
		{
			for (int j = 0; j < costs[0].size(); j++)
			{

				if (j != top2[0].first)
				{
					dp[i][j] = top2[0].second + costs[i][j];
				}
				else
				{
					dp[i][j] = top2[1].second + costs[i][j];
				}
				max_heap.push({ j,dp[i][j] });
				if (max_heap.size() > 2) max_heap.pop();
				// cout << dp[i][j] <<" " << costs[i][j] <<" " << top2[0].second << " " << top2[1].second<< endl;
			}
			top2.clear();
			while (!max_heap.empty())
			{
				top2.push_back(max_heap.top()); max_heap.pop();
			}
			reverse(top2.begin(), top2.end());
			// cout << "----------" << endl;
		}
		int min_cost = INT_MAX;
		for (int i = 0; i < dp[0].size(); i++)
		{
			min_cost = min(min_cost, dp[costs.size() - 1][i]);
		}
		return min_cost;
	}
};