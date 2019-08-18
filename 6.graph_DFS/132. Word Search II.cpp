class Solution {
public:
	/*
	 * @param start: a string
	 * @param end: a string
	 * @param dict: a set of string
	 * @return: a list of lists of string
	 */
	vector<vector<string>> findLadders(string& start, string& end, unordered_set<string>& dict) {
		// write your code here
		unordered_map<string, int> dist;
		dict.insert(start);
		dict.insert(end);
		bfs(dict, end, start, dist);
		unordered_set<string> visited;
		vector<vector<string>> res;
		vector<string> path = { start };
		visited.insert(start);
		dfs(res, path, dist, dict, end, visited);
		return res;
	}

	void dfs(vector<vector<string>>& res, vector<string>& path, unordered_map<string, int>& dist, \
		unordered_set<string>& dict, string& end, unordered_set<string>& visited)
	{
		if (path.back() == end)
		{
			res.push_back(path);
			return;
		}
		string last = path.back();
		vector<string> neighbors = findNext(last, dict);
		for (string next : neighbors)
		{
			if (dist[last] != dist[next] + 1 || visited.count(next)) continue;
			path.push_back(next);
			visited.insert(next);
			dfs(res, path, dist, dict, end, visited);
			visited.erase(next);
			path.pop_back();
		}
	}

	void bfs(unordered_set<string>& dict, string start, string end, unordered_map<string, int>& dist)
	{
		queue<string> q;
		q.push(start);
		while (!q.empty())
		{
			string cur = q.front();
			q.pop();
			vector<string> neighbors = findNext(cur, dict);
			for (string next : neighbors)
			{
				if (dist.count(next)) continue;
				dist[next] = dist[cur] + 1;
				if (next == end) return;
				q.push(next);
			}
		}
	}

	vector<string> findNext(string cur, unordered_set<string>& dict)
	{
		vector<string> res;
		for (int i = 0; i < cur.size(); i++)
		{
			for (char c = 'a'; c <= 'z'; c++)
			{
				string next = cur;
				if (cur[i] == c) continue;
				next[i] = c;
				if (dict.count(next)) res.push_back(next);
			}
		}
		return res;
	}
};