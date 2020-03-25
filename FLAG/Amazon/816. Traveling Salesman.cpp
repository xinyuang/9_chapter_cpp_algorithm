//816. Traveling Salesman
//1. It require start from 1, so use DFS or BFS to get the lowest cost
//2. if it doesn't require start from 1, sort with edge weight, union find to add the cost till all visited


class Solution {
private:
	vector<int> visited;
	int visited_number;
	int ttl_city;
public:
	/**
	 * @param n: an integer,denote the number of cities
	 * @param roads: a list of three-tuples,denote the road between cities
	 * @return: return the minimum cost to travel all cities
	 */
	int minCost(int n, vector<vector<int>>& roads) {
		// Write your code here
		ttl_city = n;
		visited = vector<int>(n + 1, 0);
		unordered_map<int, vector<pair<int, int>>> mp;
		for (int i = 0; i < roads.size(); i++)
		{
			if (!mp.count(roads[i][0])) mp[roads[i][0]] = { {roads[i][1],roads[i][2]} };
			mp[roads[i][0]].push_back({ roads[i][1],roads[i][2] });
			if (!mp.count(roads[i][1])) mp[roads[i][1]] = { {roads[i][0],roads[i][2]} };
			mp[roads[i][1]].push_back({ roads[i][0],roads[i][2] });
		}
		int cur_cost = 0;
		int min_cost = INT_MAX;
		visited_number = 1;
		visited[1] = 1;
		dfs(1, cur_cost, min_cost, mp);
		return min_cost;
	}

	void dfs(int city, int cur_cost, int& min_cost, unordered_map<int, vector<pair<int, int>>>& mp)
	{
		if (cur_cost >= min_cost) return;
		if (visited_number == ttl_city)
		{
			min_cost = cur_cost;
			return;
		}
		vector<pair<int, int>> next = mp[city];
		for (auto i : next)
		{
			int next_city = i.first;
			int next_cost = i.second;
			if (visited[next_city]) continue;
			visited[next_city] = 1;
			visited_number++;
			dfs(next_city, cur_cost + next_cost, min_cost, mp);
			visited[next_city] = 0;
			visited_number--;
		}
	}
};