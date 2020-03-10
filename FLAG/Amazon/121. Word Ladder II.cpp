//121. Word Ladder II
//1. unordered_map<string, int> dist find == dict.end()
//2. bfs get distance of each node
//3. dfs get shortest pathes

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
		dict.insert(start);
		dict.insert(end);
		queue<string> q;
		q.push(start);
		unordered_set<string> visited;
		visited.insert(start);
		unordered_map<string, int> mp;
		mp[start] = 1;
		while (!q.empty())
		{
			string cur = q.front(); q.pop();
			vector<string> next = findNext(cur, dict);
			for (string next_word : next)
			{
				if (visited.count(next_word)) continue;
				visited.insert(next_word);
				mp[next_word] = mp[cur] + 1;
				q.push(next_word);
				if (next_word == end) break;
			}
		}
		vector<vector<string>> res;
		vector<string> path = { start };
		dfs(end, mp, res, path, dict);
		return res;
	}

	void dfs(string& end, unordered_map<string, int>& dist,
		vector<vector<string>>& res, vector<string> path, unordered_set<string>& dict)
	{
		if (path.back() == end) {
			res.push_back(path);
			return;
		}

		string cur = path.back();
		vector<string> next = findNext(cur, dict);
		for (string next_word : next)
		{
			if (dist[next_word] != dist[cur] + 1) continue;
			path.push_back(next_word);
			dfs(end, dist, res, path, dict);
			path.pop_back();
		}
	}

	vector<string> findNext(string& cur, unordered_set<string>& dict)
	{
		vector<string> res;
		for (int i = 0; i < cur.size(); i++)
		{
			for (int c = 'a'; c <= 'z'; c++)
			{
				if (cur[i] == c) continue;
				string new_word = cur;
				new_word[i] = c;
				if (dict.count(new_word)) res.push_back(new_word);
			}
		}
		return res;
	}
};