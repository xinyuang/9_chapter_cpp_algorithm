//598. Zombie in Matrix
//1. count people, push zombie to queue
//2. bfs to get max_day

class Solution {
private:
	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { 1,0,-1,0 };
public:
	/**
	 * @param grid: a 2D integer grid
	 * @return: an integer
	 */
	int zombie(vector<vector<int>>& grid) {
		// write your code here
		typedef pair<pair<int, int>, int> Pos;
		queue<Pos> q;
		vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
		int max_days = 0;
		int people = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == 1)
				{
					q.push({ {i,j},0 });
					visited[i][j] = 1;
				}
				if (grid[i][j] == 0) people++;
			}
		}
		int count = 0;
		while (!q.empty())
		{
			Pos cur = q.front(); q.pop();
			int x = cur.first.first;
			int y = cur.first.second;
			int cur_day = cur.second;

			for (int i = 0; i < 4; i++)
			{
				int new_x = x + dx[i];
				int new_y = y + dy[i];
				if (!is_valid(new_x, new_y, grid) || grid[new_x][new_y] == 2 || visited[new_x][new_y]) continue;
				q.push({ {new_x,new_y}, cur_day + 1 });
				visited[new_x][new_y] = 1;
				count++;
				max_days = max(max_days, cur_day + 1);
			}
		}
		if (count != people) return -1;
		return max_days;
	}

	bool is_valid(int x, int y, vector<vector<int>>& grid)
	{
		if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) return true;
		return false;
	}
};