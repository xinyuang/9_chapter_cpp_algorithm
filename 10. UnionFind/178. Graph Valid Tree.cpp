//178. Graph Valid Tree
//
//check valid tree:
//1. node number == edge number + 1
//2. only one island


class Solution {
private:
	vector<int> father;
public:
	/**
	 * @param n: An integer
	 * @param edges: a list of undirected edges
	 * @return: true if it's a valid tree, or false
	 */
	bool validTree(int n, vector<vector<int>>& edges) {
		// write your code here
		if (edges.size() + 1 != n) return false;
		for (int i = 0; i < n; i++) father.push_back(i);
		int count = n;
		for (int i = 0; i < edges.size(); i++)
		{
			addEdge(count, edges[i]);
		}
		return count == 1;
	}

	void addEdge(int& count, vector<int>& edge)
	{
		int rootA = findRoot(edge[0]);
		int rootB = findRoot(edge[1]);
		if (rootA != rootB)
		{
			father[rootB] = rootA;
			count--;
		}
	}

	int findRoot(int x)
	{
		while (father[x] != x)
		{
			x = father[x];
		}
		return x;
	}
};