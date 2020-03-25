//1391. Check if There is a Valid Path in a Grid
//1. create unordered_map<int, vector<unordered_map<int>>> to store 4 dir's availabel pattern
//2. BFS all availabel position use queue<pair<int, int>>, if position is{ r - 1,c - 1 } return true

class Solution {
private:
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
public:
	bool hasValidPath(vector<vector<int>>& grid) {
		unordered_map<int, vector<unordered_set<int>>> mp;
		mp[1] = { {},{},{1,4,6},{1,3,5} };
		mp[2] = { {2,3,4},{2,5,6},{},{} };
		mp[3] = { {},{2,5,6},{1,4,6},{} };
		mp[4] = { {},{2,5,6},{},{1,3,5} };
		mp[5] = { {2,3,4},{},{1,4,6},{} };
		mp[6] = { {2,3,4},{},{},{1,3,5} };
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
		visited[0][0] = 1;
		int count = 0;
		while (!q.empty())
		{
			pair<int, int> cur = q.front(); q.pop();
			count++;
			if (cur.first + 1 == grid.size() && cur.second + 1 == grid[0].size()) return true;
			for (int i = 0; i < 4; i++)
			{
				int x = cur.first + dx[i];
				int y = cur.second + dy[i];
				if (!is_valid(x, y, grid)) continue;
				if (visited[x][y]) continue;
				if (!mp[grid[cur.first][cur.second]][i].count(grid[x][y])) continue;
				q.push({ x,y });
				visited[x][y] = 1;
			}
		}
		return false;
	}

	bool is_valid(int x, int y, vector<vector<int>>& grid)
	{
		if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) return true;
		return false;
	}
};
