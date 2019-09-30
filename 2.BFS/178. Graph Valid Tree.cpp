//BFS
class Solution {
public:
	/**
	 * @param n: An integer
	 * @param edges: a list of undirected edges
	 * @return: true if it's a valid tree, or false
	 */
	bool validTree(int n, vector<vector<int>>& edges) {
		// write your code here
		unordered_map<int, unordered_set<int>> graph;
		for (int i = 0; i < edges.size(); i++)
		{
			graph[edges[i][0]].insert(edges[i][1]);
			graph[edges[i][1]].insert(edges[i][0]);
		}
		queue<int> q;
		q.push(0);
		unordered_set<int> visited;
		visited.insert(0);
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			unordered_set<int> neighbors = graph[cur];
			for (int next : neighbors)
			{
				if (visited.count(next)) return false;
				visited.insert(next);
				q.push(next);
				graph[next].erase(cur);
			}
		}
		return visited.size() == n;
	}
};

//DFS
class Solution {
public:
	/**
	 * @param n: An integer
	 * @param edges: a list of undirected edges
	 * @return: true if it's a valid tree, or false
	 */
	bool validTree(int n, vector<vector<int>>& edges) {
		// write your code here
		unordered_map<int, unordered_set<int>> graph;
		for (int i = 0; i < edges.size(); i++)
		{
			graph[edges[i][0]].insert(edges[i][1]);
			graph[edges[i][1]].insert(edges[i][0]);
		}
		queue<int> q;
		q.push(0);
		unordered_set<int> visited;
		visited.insert(0);
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			unordered_set<int> neighbors = graph[cur];
			for (int next : neighbors)
			{
				if (visited.count(next)) return false;
				visited.insert(next);
				q.push(next);
				graph[next].erase(cur);
			}
		}
		return visited.size() == n;
	}
};



class Solution {
public:
	/**
	 * @param n: An integer
	 * @param edges: a list of undirected edges
	 * @return: true if it's a valid tree, or false
	 */
	bool validTree(int n, vector<vector<int>>& edges) {
		// write your code here
		if (n <= 1) return true;
		unordered_map<int, vector<int>> graph;
		for (int i = 0; i < edges.size(); i++)
		{
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}
		if (graph.size() != n) return false;
		vector<bool> visited(n, false);
		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				bool res = hasCycle(graph, i, visited, -1);
				if (res) return false;
			}
		}
		return true;
	}

	bool hasCycle(unordered_map<int, vector<int>>& graph, int cur, vector<bool>& visited, int parent)
	{
		visited[cur] = true;
		vector<int> neighbors = graph[cur];
		for (int next : neighbors)
		{
			if (!visited[next])
			{
				bool res = hasCycle(graph, next, visited, cur);
				if (res) return true;
			}
			else
			{
				if (parent != next) return true;
			}
		}
		return false;
	}
};