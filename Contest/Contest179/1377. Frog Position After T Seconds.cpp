//1377. Frog Position After T Seconds
//Given an undirected tree consisting of n vertices numbered from 1 to n.A frog starts jumping from the vertex 1. In one second, the frog jumps from its current vertex to another unvisited vertex if they are directly connected.The frog can not jump back to a visited vertex.In case the frog can jump to several vertices it jumps randomly to one of them with the same probability, otherwise, when the frog can not jump to any unvisited vertex it jumps forever on the same vertex.
//
//The edges of the undirected tree are given in the array edges, where edges[i] = [fromi, toi] means that exists an edge connecting directly the vertices fromi and toi.
//
//Return the probability that after t seconds the frog is on the vertex target.

// in the tree cannot go back to visited node
// but if no way to go, frog can stay in same node
// BFS, within t step, can reach target nor not
// when reach new node, store its probability 
// prob[new_node] = prob[cur] * (1/#choice)

class Solution {
public:
	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		unordered_map<int, vector<int>> graph;
		for (int i = 0; i < edges.size(); i++)
		{
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}
		queue<int> q;
		q.push(1);
		double prob = 1;
		int step = 0;
		unordered_set<int> visited;
		visited.insert(1);
		unordered_map<int, double> probs;
		probs[1] = 1;
		while (!q.empty())
		{
			int q_size = q.size();
			step++;

			for (int i = 0; i < q_size; i++)
			{
				int cur = q.front(); q.pop();
				vector<int> next = graph[cur];
				if (step > t) break;
				double choice = (cur == 1) ? (double)next.size() : (double)next.size() - 1;
				if (choice == 0) {
					if (cur == target) return probs[cur];
					continue;
				}
				for (int j = 0; j < next.size(); j++)
				{

					if (visited.count(next[j])) continue;
					probs[next[j]] = probs[cur] * (1 / choice);
					if (next[j] == target && t == step) return probs[next[j]];
					if (step > t) return 0;
					q.push(next[j]);
					visited.insert(next[j]);
				}
			}
		}
		return 0;
	}
};