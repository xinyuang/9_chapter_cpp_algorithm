// Course Schedule II
class Solution {
public:
	/*
	 * @param numCourses: a total of n courses
	 * @param prerequisites: a list of prerequisite pairs
	 * @return: the course order
	 */
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		// write your code here
		unordered_map<int, int> indegree;
		unordered_map<int, vector<int>> graph;
		for (int i = 0; i < prerequisites.size(); i++)
		{
			indegree[prerequisites[i].first]++;
			graph[prerequisites[i].second].push_back(prerequisites[i].first);
		}
		queue<int> q;
		for (int i = 0; i < numCourses; i++)
		{
			if (!indegree.count(i)) q.push(i);
		}
		vector<int> res;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			res.push_back(cur);
			for (int ele : graph[cur])
			{
				indegree[ele]--;
				if (indegree[ele] == 0) q.push(ele);
			}
		}
		if (res.size() != numCourses) return {};
		return res;
	}
};