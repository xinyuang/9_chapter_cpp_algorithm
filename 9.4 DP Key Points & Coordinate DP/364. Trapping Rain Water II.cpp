// Trapping Rain Water II
// min_heap store (i,j) - height
// Traverse outer layer go from the lowest one

class Solution {
public:
	/**
	 * @param heights: a matrix of integers
	 * @return: an integer
	 */
	int trapRainWater(vector<vector<int>>& heights) {
		// write your code here

		//     1,2,5,3
		//     3,2,5,1
		//     6,5,4,2
		//     6,4,2,7

		if (heights.size() <= 2 || heights[0].size() <= 2) return 0;

		typedef pair<pair<int, int>, int> PosV; // position - height
		struct compare {
			bool operator()(PosV a, PosV b)
			{
				return a.second > b.second;
			}
		};
		priority_queue<PosV, vector<PosV>, compare> min_heap;
		vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
		for (int j = 0; j < heights[0].size(); j++)
		{
			min_heap.push({ {0,j},heights[0][j] });
			visited[0][j] = true;
			min_heap.push({ {heights.size() - 1, j},heights[heights.size() - 1][j] });
			visited[heights.size() - 1][j] = true;
		}

		for (int i = 1; i < heights.size() - 1; i++)
		{
			min_heap.push({ {i,0},heights[i][0] });
			visited[i][0] = true;
			min_heap.push({ {i, heights[0].size() - 1},heights[i][heights[0].size() - 1] });
			visited[i][heights[0].size() - 1] = true;
		}
		int g_height = 0;
		int water = 0;

		while (!min_heap.empty())
		{
			PosV cur = min_heap.top(); min_heap.pop();
			int x = cur.first.first;
			int y = cur.first.second;
			int cur_height = cur.second;
			if (g_height < cur_height) g_height = cur_height;
			water += (g_height - cur_height);
			for (int i = 0; i < 4; i++)
			{
				int new_x = x + delta_x[i];
				int new_y = y + delta_y[i];
				if (!is_valid(new_x, new_y, heights) || visited[new_x][new_y]) continue;
				min_heap.push({ {new_x,new_y},heights[new_x][new_y] });
				visited[new_x][new_y] = true;
			}
		}
		return water;
	}

	bool is_valid(int x, int y, vector<vector<int>>& heights)
	{
		if (x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size()) return true;
		return false;
	}
private:
	int delta_x[4] = { 1,0,-1,0 };
	int delta_y[4] = { 0,-1,0,1 };
};