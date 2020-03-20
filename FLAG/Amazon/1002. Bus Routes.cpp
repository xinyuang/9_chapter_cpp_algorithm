//1002. Bus Routes
//1. map station to bus
//2. take all possible bus to all stations, dist[next_station] = dist[cur_station] + 1
//3. BFS till next_station is target station

class Solution {
public:
	/**
	 * @param routes:  a list of bus routes
	 * @param S: start
	 * @param T: destination
	 * @return: the least number of buses we must take to reach destination
	 */
	int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
		// Write your code here
		unordered_map<int, unordered_set<int>> station_bus;
		unordered_set<int> start;
		for (int i = 0; i < routes.size(); i++)
		{
			for (int j = 0; j < routes[i].size(); j++)
			{
				station_bus[routes[i][j]].insert(i);
			}
		}
		queue<int> q;
		unordered_set<int> used_bus;
		unordered_map<int, int> dist;
		q.push(S);
		dist[S] = 0;
		unordered_set<int> used_station;
		while (!q.empty())
		{
			int cur_station = q.front(); q.pop();
			unordered_set<int> available_bus = station_bus[cur_station];
			for (int bus : available_bus)
			{
				if (used_bus.count(bus)) continue;
				used_bus.insert(bus);
				vector<int> next_stations = routes[bus];
				for (int st : next_stations)
				{
					if (dist.count(st)) continue;
					dist[st] = dist[cur_station] + 1;
					if (st == T) return dist[st];
					q.push(st);
				}
			}
		}
		return -1;
	}
};
