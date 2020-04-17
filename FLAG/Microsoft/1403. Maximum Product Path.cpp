//1403. Maximum Product Path
//1. build unordered_map<int, vector<int>> graph
//2. dfs to get max product((cur_prod * weight) % mod + mod) % mod

class Solution {
public:
	/**
	 * @param x: The end points of edges set
	 * @param y: The end points of edges set
	 * @param d: The weight of points set
	 * @return: Return the maximum product
	 */
	int getProduct(vector<int>& x, vector<int>& y, vector<int>& d) {
		// Write your code here
		unordered_map<int, vector<int>> graph;
		for (int i = 0; i < x.size(); i++)
		{
			graph[x[i]].push_back(y[i]);
			graph[y[i]].push_back(x[i]);
		}
		long max_prod = INT_MIN;
		int mod = pow(10, 9) + 7;
		long prod = d[0] % mod;
		dfs(1, 1, prod, graph, max_prod, mod, d);
		return max_prod;
	}

	void dfs(int father, int cur, long prod, unordered_map<int, vector<int>>& graph, long& max_prod, int& mod,
		vector<int>& d)
	{
		if (cur != 1 && graph[cur].size() == 1)
		{
			// cout << cur << " " << prod << endl;
			max_prod = max(max_prod, prod);
			return;
		}
		vector<int> neighbor = graph[cur];
		for (int i = 0; i < neighbor.size(); i++)
		{
			if (neighbor[i] == father) continue;
			int nextprod = (d[neighbor[i] - 1] * prod % mod + mod) % mod;
			dfs(cur, neighbor[i], nextprod, graph, max_prod, mod, d);
		}
	}
};