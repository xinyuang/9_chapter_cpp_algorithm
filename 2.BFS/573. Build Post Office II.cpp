//573. Build Post Office II
//1. from each house bfs, dist[i][j] = dist[i][j] + cur_house_dist, count access point number
//2. if (acess_point number == house number && A[i][j] == 0) res = min(res, dist[i][j])

typedef pair<pair<int, int>, int> Pos;  // cur x,y dist

class Solution {
public:
	/**
	 * @param grid: a 2D grid
	 * @return: An integer
	 */
	int shortestDistance(vector<vector<int>>& grid) {
		// write your code here
		int house_number = 0;
		vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), 0));
		vector<vector<int>> visit(grid.size(), vector<int>(grid[0].size(), 0));
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == 1) {
					house_number++;
					bfs(i, j, dist, visit, grid);  // calculate dist to all houses
				}
			}
		}

		int res = INT_MAX;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (visit[i][j] == house_number && grid[i][j] == 0) res = min(res, dist[i][j]);
			}
		}
		if (res == INT_MAX) return -1;
		return res;
	}

	void bfs(int x, int y, vector<vector<int>>& dist, vector<vector<int>>& visit, vector<vector<int>>& grid)
	{
		vector<vector<int>> count(grid.size(), vector<int>(grid[0].size(), 0));
		count[x][y] = 1;
		queue<Pos> q;
		q.push({ {x,y},0 });
		while (!q.empty())
		{
			Pos cur = q.front(); q.pop();
			int c_x = cur.first.first;
			int c_y = cur.first.second;
			for (int i = 0; i < 4; i++)
			{
				int n_x = c_x + dx[i];
				int n_y = c_y + dy[i];
				if (!is_valid(n_x, n_y, grid) || count[n_x][n_y]) continue;
				count[n_x][n_y] = 1;
				dist[n_x][n_y] += cur.second + 1;
				q.push({ {n_x,n_y},cur.second + 1 });
				visit[n_x][n_y]++;
			}
		}
	}

	bool is_valid(int x, int y, vector<vector<int>>& grid)
	{
		if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0) return true;
		return false;
	}

private:
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
};