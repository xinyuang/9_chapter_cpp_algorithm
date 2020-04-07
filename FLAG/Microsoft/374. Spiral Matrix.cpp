//374. Spiral Matrix
//dx dy, when hit the wall or visited, change the direction, while (count < ttl)

class Solution {
private:
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	int dir[4] = { 0,1,2,3 };
public:
	/**
	 * @param matrix: a matrix of m x n elements
	 * @return: an integer list
	 */
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		// write your code here
		if (matrix.size() == 0 || matrix[0].size() == 0) return {};
		vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
		vector<int> res;
		int count = matrix.size() * matrix[0].size();
		int idx = 1;
		int x = 0, y = 0;
		int i = 0;
		res.push_back({ matrix[x][y] });
		visited[x][y] = 1;
		while (idx < count)
		{
			int new_x = x + dx[dir[i]];
			int new_y = y + dy[dir[i]];
			if (!is_valid(new_x, new_y, matrix) || visited[new_x][new_y] == 1)
			{
				i++;
				i = i % 4;
			}
			else
			{
				visited[new_x][new_y] = 1;
				res.push_back(matrix[new_x][new_y]);
				x = new_x;
				y = new_y;
				idx++;
			}
		}
		return res;
	}

	bool is_valid(int x, int y, vector<vector<int>>& matrix)
	{
		if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size()) return true;
		return false;
	}
};