// Word ladder II
			//                a4
			//               / \
            //              d3  r0
			//             / \   \
            //             b2  g2 j0
			//             \  /   /
			//              e1   t0
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
		unordered_map<string, int> distance;
		bfs(end, start, distance, dict);
		vector<vector<string>> res;
		vector<string> path = { start };
		unordered_set<string> visited;
		dfs(start, end, distance, path, res, dict, visited);
		return res;
	}

	void bfs(string start, string end, unordered_map<string, int>& distance, unordered_set<string>& dict)
	{
		queue<string> q;
		q.push(start);
		distance[start] = 0;
		unordered_set<string> visited = { start };
		while (!q.empty())
		{
			string cur = q.front();
			q.pop();
			vector<string> neighbors = findNext(cur, dict, visited);
			for (string neighbor : neighbors)
			{
				distance[neighbor] = distance[cur] + 1;
				visited.insert(neighbor);
				q.push(neighbor);
				cout << neighbor << endl;
				if (neighbor == end) return;
			}
		}
	}

	vector<string> findNext(string cur, unordered_set<string>& dict, unordered_set<string>& visited)
	{
		vector<string> res;
		for (int i = 0; i < cur.size(); i++)
		{
			for (char c = 'a'; c <= 'z'; c++)
			{
				if (cur[i] == c) continue;
				string new_str = cur;
				new_str[i] = c;
				if (visited.count(new_str))continue;
				if (dict.count(new_str)) res.push_back(new_str);
			}
		}
		return res;
	}

	void dfs(string start, string end, unordered_map<string, int>& distance, vector<string>& path, \
		vector<vector<string>>& res, unordered_set<string>& dict, unordered_set<string>& visited)
	{

		if (path.back() == end)
		{
			res.push_back(path);

			return;
		}
		vector<string> neighbors = findNext(start, dict, visited);
		for (string neighbor : neighbors)
		{
			if (distance[neighbor] + 1 != distance[start]) continue;
			path.push_back(neighbor);
			visited.insert(neighbor);
			dfs(neighbor, end, distance, path, res, dict, visited);
			visited.erase(neighbor);
			path.pop_back();
		}
	}
};


// word ladder I
class Solution {
public:
	/*
	 * @param start: a string
	 * @param end: a string
	 * @param dict: a set of string
	 * @return: An integer
	 */
	int ladderLength(string& start, string& end, unordered_set<string>& dict) {
		// write your code here
		dict.insert(start);
		dict.insert(end);
		unordered_set<string> visited;
		queue<string> q;
		visited.insert(start);
		q.push(start);
		int len = 1;
		while (!q.empty())
		{
			int q_size = q.size();
			len++;
			for (int i = 0; i < q_size; i++)
			{
				string cur = q.front(); q.pop();
				vector<string> next = findNext(cur, dict);
				for (string ele : next)
				{
					if (visited.count(ele)) continue;
					if (ele == end) return len;
					q.push(ele);
					visited.insert(ele);
				}
			}
		}
		return -1;
	}

	vector<string> findNext(string cur, unordered_set<string>& dict)
	{
		vector<string> res;
		for (int i = 0; i < cur.size(); i++)
		{
			for (char c = 'a'; c < 'z'; c++)
			{
				if (cur[i] == c) continue;
				string str = cur;
				str[i] = c;
				if (dict.count(str)) res.push_back(str);
			}
		}
		return res;
	}
};

// used dist map 
class Solution {
public:
	/*
	 * @param start: a string
	 * @param end: a string
	 * @param dict: a set of string
	 * @return: An integer
	 */
	int ladderLength(string& start, string& end, unordered_set<string>& dict) {
		// write your code here
		dict.insert(start);
		dict.insert(end);
		unordered_map<string, int> dist;
		queue<string> q;
		q.push(start);
		dist[start] = 1;
		while (!q.empty())
		{
			string cur = q.front(); q.pop();
			vector<string> next = findNext(cur, dict);
			for (string ele : next)
			{
				if (dist.count(ele)) continue;
				dist[ele] = dist[cur] + 1;
				if (ele == end) return dist[ele];
				q.push(ele);
			}
		}
		return -1;
	}

	vector<string> findNext(string cur, unordered_set<string>& dict)
	{
		vector<string> res;
		for (int i = 0; i < cur.size(); i++)
		{
			for (char c = 'a'; c < 'z'; c++)
			{
				if (cur[i] == c) continue;
				string str = cur;
				str[i] = c;
				if (dict.count(str)) res.push_back(str);
			}
		}
		return res;
	}
};