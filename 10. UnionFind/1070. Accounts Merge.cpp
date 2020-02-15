class Solution {
public:
	/**
	 * @param accounts: List[List[str]]
	 * @return: return a List[List[str]]
	 */
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		// write your code here
		vector<int> father(accounts.size(), 0);
		for (int i = 0; i < accounts.size(); i++) father[i] = i;
		unordered_map<string, int> mp;
		for (int i = 0; i < accounts.size(); i++)
		{
			for (int j = 1; j < accounts[i].size(); j++)
			{
				if (mp.count(accounts[i][j])) addEdge(mp[accounts[i][j]], i, father);
				else {
					mp[accounts[i][j]] = i;
				}
			}
		}
		unordered_map<int, set<string>> cluster;
		for (int i = 0; i < accounts.size(); i++)
		{
			int parent = findFather(i, father);
			for (int j = 1; j < accounts[i].size(); j++)
			{
				cluster[parent].insert(accounts[i][j]);
			}
		}
		vector<vector<string>> res;
		for (auto c : cluster)
		{
			vector<string> user;
			user.push_back(accounts[c.first][0]);
			for (string email : c.second)
			{
				user.push_back(email);
			}
			res.push_back(user);
		}
		return res;
	}

	void addEdge(int x, int y, vector<int>& father)
	{
		int rootX = findFather(x, father);
		int rootY = findFather(y, father);
		if (rootX != rootY)
		{
			father[rootX] = rootY;
		}
	}

	int findFather(int x, vector<int>& father)
	{
		while (father[x] != x)
		{
			x = father[x];
		}
		return x;
	}
};