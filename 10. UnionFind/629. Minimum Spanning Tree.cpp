//629. Minimum Spanning Tree
//
//if use set to record visit, map<string, string> as father, will be slow.
//to speed up, idx the city using map<string, int> mp, init vector<int> father(#city, -1)
//sort the weighted connect(including city alphabet), then union find
//only when the area of island get increased, add connection to the res;

/**
 * Definition for a Connection.
 * class Connection {
 * public:
 *   string city1, city2;
 *   int cost;
 *   Connection(string& city1, string& city2, int cost) {
 *       this->city1 = city1;
 *       this->city2 = city2;
 *       this->cost = cost;
 * }
 */

class compare {
public:
	bool operator()(const Connection& a, const Connection& b)
	{
		if (a.cost == b.cost)
		{
			if (a.city1 == b.city1)
			{
				return a.city2 < b.city2;
			}
			return a.city1 < b.city1;
		}
		return a.cost < b.cost;
	}
} com;

class Solution {
private:
	vector<int> father;
public:
	/**
	 * @param connections given a list of connections include two cities and cost
	 * @return a list of connections from results
	 */
	vector<Connection> lowestCost(vector<Connection>& connections) {
		// Write your code here
		vector<Connection> res;
		unordered_map<string, int> mp;
		sort(connections.begin(), connections.end(), com);
		int idx = 0;
		for (int i = 0; i < connections.size(); i++)
		{
			if (!mp.count(connections[i].city1)) mp[connections[i].city1] = idx++;
			if (!mp.count(connections[i].city2)) mp[connections[i].city2] = idx++;
		}
		father = vector<int>(idx, -1);
		for (int i = 0; i < connections.size(); i++)
		{
			int a_idx = mp[connections[i].city1];
			int b_idx = mp[connections[i].city2];
			addEdge(a_idx, b_idx, res, connections[i]);
		}
		if (idx != res.size() + 1) return {};
		return res;
	}

	void addEdge(int x, int y, vector<Connection>& res, Connection& edge)
	{
		int rootA = findRoot(x);
		int rootB = findRoot(y);
		if (rootA != rootB)
		{
			father[rootB] = rootA;
			res.push_back(edge);
		}
	}

	int findRoot(int x)
	{
		while (father[x] != -1)
		{
			x = father[x];
		}
		return x;
	}
};