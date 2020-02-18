//432. Find the Weak Connected Component in the Directed Graph
//
//1. notice the label can be negative, so use a map to map label and idx first
//2. UnionFind father with idx
//3. cluster graph use map

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */


	class Solution {
	private:
		vector<int> father;
	public:
		/*
		 * @param nodes: a array of Directed graph node
		 * @return: a connected set of a directed graph
		 */
		vector<vector<int>> connectedSet2(vector<DirectedGraphNode*> nodes) {
			// write your code here
			father = vector<int>(nodes.size() + 1, -1);
			unordered_map<int, int> idx;
			for (int i = 0; i < nodes.size(); i++)
			{
				father[i] = i;
				idx[nodes[i]->label] = i;
			}
			for (int i = 0; i < nodes.size(); i++)
			{
				for (int j = 0; j < nodes[i]->neighbors.size(); j++)
				{
					int idx_a = idx[nodes[i]->label];
					int idx_b = idx[nodes[i]->neighbors[j]->label];
					addEdge(idx_a, idx_b);
				}
			}
			map<int, set<int>> mp;
			for (int i = 0; i < nodes.size(); i++)
			{
				if (!nodes[i]) continue;
				int cur = nodes[i]->label;
				int cur_root = findRoot(idx[cur]);
				mp[cur_root].insert(cur);
			}
			vector<vector<int>> res;
			for (auto cluster : mp)
			{

				vector<int> ele_list = {};
				for (auto ele : cluster.second)
				{
					ele_list.push_back(ele);
				}
				res.push_back(ele_list);
			}
			return res;
		}

		void addEdge(int a, int b)
		{
			int rootA = findRoot(a);
			int rootB = findRoot(b);
			if (rootA != rootB)
			{
				father[rootA] = rootB;
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