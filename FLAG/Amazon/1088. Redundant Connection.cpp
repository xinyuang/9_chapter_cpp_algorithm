//1088. Redundant Connection
//1. union find
//2. if father1 == father2 redundant connection

class Solution {
public:
	/**
	 * @param edges: List[List[int]]
	 * @return: List[int]
	 */
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		// write your code here
		vector<int> father(edges.size() + 1, 0);
		for (int i = 0; i <= edges.size(); i++) father[i] = i;
		for (int i = 0; i <= edges.size(); i++)
		{
			int n1 = edges[i][0];
			int n2 = edges[i][1];
			int root1 = findFather(edges[i][0], father);
			int root2 = findFather(edges[i][1], father);
			if (root1 == root2) return edges[i];
			else father[root1] = root2;
		}
		return {};
	}

	int findFather(int x, vector<int>& father)
	{
		while (x != father[x])
		{
			x = father[x];
		}
		return x;
	}
};
