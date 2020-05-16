//1395. The Barycentre Of The Trees
//1. build unordered_map<int, vector<int>> graph, (undirected)
//2. def dp[i] = substree  size  dp.size() == graph.size() + 1 = x.size() + 2
//3. dfs get current node min(subtree size) = min(n - dp[i], min(dp[j]) update res

class Solution {
public:
	/**
	 * @param x: The vertexes of the edges
	 * @param y: The vertexes of the edges
	 * @return: Return the index of barycentre
	 */
	int getBarycentre(vector<int>& x, vector<int>& y) {
		// Write your code here
		// step1 build graph
		if (x.size() != y.size()) return 0;
		unordered_map<int, vector<int>> graph;
		for (int i = 0; i < x.size(); i++)
		{
			if (!graph.count(x[i])) graph[x[i]] = {};
			if (!graph.count(y[i])) graph[y[i]] = {};
			graph[x[i]].push_back(y[i]);
			graph[y[i]].push_back(x[i]);
		}

		//step2 dfs the graph from a random node, update the x value
		// define x value is the minimum size among all subtree
		// x = min(subtree[i])  parentTree = N - sum(subtree[i])
		// dp[i] stores the size of current tree (substree[i])
		int center = 0;
		int g_x = INT_MAX;
		int father = x[0];
		int cur = x[0];
		vector<int> dp(graph.size() + 1, 0);
		dfs(center, g_x, father, cur, graph, dp);
		return center;
	}

	void dfs(int& center, int& g_x, int father, int cur, unordered_map<int, vector<int>>& graph,
		vector<int>& dp)
	{
		dp[cur] = 1;
		int cur_x = INT_MAX;
		vector<int> neighbor = graph[cur];
		for (int next : neighbor)
		{
			if (next == father) continue;
			dfs(center, g_x, cur, next, graph, dp);
			cur_x = min(cur_x, dp[next]);
			dp[cur] += dp[next];  // sum of all subtree size plus 1 = size of current tree
		}
		cur_x = min(cur_x, (int)graph.size() - dp[cur]);
		dp[cur] = cur_x;
		if (cur_x < g_x || (cur_x == g_x && cur < center))
		{
			g_x = cur_x;
			center = cur;
		}
	}
};