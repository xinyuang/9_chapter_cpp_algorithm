//431. Connected Component in Undirected Graph
//
//1. notice the label can be negative, so use a map to map label and idx first
//2. UnionFind father with idx
//3. cluster graph use map


/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


	class Solution {
	private:
		vector<int> father;
	public:
		/*
		 * @param nodes: a array of Undirected graph node
		 * @return: a connected set of a Undirected graph
		 */
		vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
			// write your code here
			father = vector<int>(nodes.size(), -1);
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
					addEdge(idx[nodes[i]->label], idx[nodes[i]->neighbors[j]->label]);
				}
			}
			map<int, set<int>> cluster;
			for (int i = 0; i < nodes.size(); i++)
			{
				int cur = nodes[i]->label;
				int cur_root = findRoot(idx[cur]);
				cluster[cur_root].insert(cur);
			}
			vector<vector<int>> res;
			for (auto st : cluster)
			{
				vector<int> cur_list;
				for (auto ele : st.second)
				{
					cur_list.push_back(ele);
				}
				res.push_back(cur_list);
			}
			return res;
		}

		void addEdge(int a, int b)
		{
			int root_a = findRoot(a);
			int root_b = findRoot(b);
			if (root_b != root_a)
			{
				father[root_a] = root_b;
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