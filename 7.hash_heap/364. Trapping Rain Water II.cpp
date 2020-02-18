// Trapping Rain Water II
// min_heap pos (i,j) - height
// Traverse outer layer go from the lowest one
// water_line = max(water_line, cur_height)
// if visited continue

class Solution {
private:
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
public:
	/**
	 * @param heights: a matrix of integers
	 * @return: an integer
	 */
	int trapRainWater(vector<vector<int>>& heights) {
		// write your code here
		typedef pair<pair<int, int>, int> Pos; // {{i,j},h[i][j]}
		class com {
		public:
			bool operator()(const Pos& a, const Pos& b)
			{
				return a.second > b.second;
			}
		};
		vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
		priority_queue<Pos, vector<Pos>, com> min_heap;
		for (int i = 0; i < heights.size(); i++)
		{
			min_heap.push({ {i,0}, heights[i][0] });
			min_heap.push({ {i,heights[0].size() - 1},heights[i][heights[0].size() - 1] });
			visited[i][0] = true;
			visited[i][heights[0].size() - 1] = true;
		}
		for (int j = 1; j < heights[0].size() - 1; j++)
		{
			min_heap.push({ {0,j},heights[0][j] });
			min_heap.push({ {heights.size() - 1,j},heights[heights.size() - 1][j] });
			visited[0][j] = true;
			visited[heights.size() - 1][j] = true;
		}
		int global_line = 0;
		int water = 0;

		while (!min_heap.empty())
		{
			Pos cur = min_heap.top(); min_heap.pop();
			int x = cur.first.first;
			int y = cur.first.second;
			water += max(0, global_line - cur.second);
			global_line = max(global_line, cur.second);
			for (int i = 0; i < 4; i++)
			{
				int new_x = x + dx[i];
				int new_y = y + dy[i];
				if (!is_valid(new_x, new_y, heights)) continue;
				if (visited[new_x][new_y]) continue;
				visited[new_x][new_y] = true;
				min_heap.push({ {new_x,new_y},heights[new_x][new_y] });
			}
		}
		return water;
	}

	bool is_valid(int x, int y, vector<vector<int>>& heights)
	{
		if (x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size()) return true;
		return false;
	}
};