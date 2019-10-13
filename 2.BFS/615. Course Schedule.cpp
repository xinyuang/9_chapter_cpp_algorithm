// Course Schedule 
class Solution {
public:
	/*
	 * @param numCourses: a total of n courses
	 * @param prerequisites: a list of prerequisite pairs
	 * @return: true if can finish all courses or false
	 */
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		// write your code here
		unordered_map<int, int> indegree;
		unordered_map<int, vector<int>> graph;
		for (int i = 0; i < prerequisites.size(); i++)
		{
			indegree[prerequisites[i].first]++;
			graph[prerequisites[i].second].push_back(prerequisites[i].first);
		}
		queue<int> q;
		int n = numCourses;
		for (int i = 0; i < n; i++)
		{
			if (!indegree.count(i) || indegree[i] == 0) q.push(i);
		}
		int res = 0;
		while (!q.empty())
		{
			int cur = q.front();
			res++;
			q.pop();
			for (int neighbor : graph[cur])
			{
				indegree[neighbor]--;
				if (indegree[neighbor] == 0)
				{
					q.push(neighbor);
				}
			}
		}
		return res == n;
	}
};