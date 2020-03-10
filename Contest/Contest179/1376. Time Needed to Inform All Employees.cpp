//1376. Time Needed to Inform All Employees

// get the ttl time to iterate through whole tree
// BFS and store current node ttl time
// get the max(ttl_time) among all leaves

class Solution {
public:
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		if (manager.size() == 0 || informTime.size() == 0 || manager.size() != informTime.size()) return 0;
		unordered_map<int, vector<int>> mp;
		unordered_map<int, int> use_time;
		for (int i = 0; i < manager.size(); i++)
		{
			if (!mp.count(i)) mp[i] = {};
			mp[manager[i]].push_back(i);
			if (!use_time.count(i)) use_time[i] = informTime[i];
			else use_time[i] = max(use_time[i], informTime[i]);
		}
		queue<int> q;
		unordered_map<int, int> ttl_time;
		q.push(-1);
		int max_ttl_time = 0;
		while (!q.empty())
		{
			int q_size = q.size();
			int level_max = 0;
			for (int i = 0; i < q_size; i++)
			{
				int cur = q.front(); q.pop();
				int cur_time = use_time[cur];

				level_max = max(level_max, cur_time);
				vector<int> neighbor = mp[cur];
				if (neighbor.size() == 0)
				{
					max_ttl_time = max(max_ttl_time, ttl_time[cur]);
				}
				for (int e : neighbor)
				{
					ttl_time[e] = ttl_time[cur] + use_time[e];
					q.push(e);
				}

			}
		}

		return max_ttl_time;
	}
};