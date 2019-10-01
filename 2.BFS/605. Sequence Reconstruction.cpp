// Sequence Reconstruction
// 1. construct graph <node, neighbors> <int, vector<int>>
// 2. construct indegree <node, indegree>  <int,int>
// 3. BFS queue 
class Solution {
public:
	/**
	 * @param org: a permutation of the integers from 1 to n
	 * @param seqs: a list of sequences
	 * @return: true if it can be reconstructed only one or false
	 */
	bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
		// write your code here
		unordered_map<int, int> indegree;
		unordered_map<int, vector<int>> graph;
		for (auto seq : seqs)
		{
			if (seq.size() == 0) continue;
			for (int i = 0; i < seq.size() - 1; i++)
			{
				graph[seq[i]].push_back(seq[i + 1]);
				indegree[seq[i + 1]]++;
			}
			if (!graph.count(seq.back())) graph[seq.back()] = {};
			if (!indegree.count(seq[0])) indegree[seq[0]] = 0;


		}
		queue<int> q;
		if (graph.size() != org.size()) return false;
		if (org.size() == 0) return true;
		q.push(org[0]);
		int idx = 0;
		while (!q.empty())
		{
			if (q.size() > 1) return false;
			int cur = q.front();
			q.pop();
			if (idx > org.size() - 1 || org[idx++] != cur) return false;
			for (int neighbor : graph[cur])
			{
				indegree[neighbor]--;
				if (indegree[neighbor] == 0)
				{
					q.push(neighbor);
				}
			}
		}
		if (idx != org.size()) return false;
		return true;
	}
};