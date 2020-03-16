//1380. Lucky Numbers in a Matrix
//if row_min and col_max, res.push_back(m[i][j])

class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		vector<vector<int>> c_max(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size(); i++)
		{
			int col_max = 0;
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] < matrix[i][col_max])
				{
					col_max = j;
				}
			}
			c_max[i][col_max] = 1;
		}

		vector<vector<int>> r_min(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int j = 0; j < matrix[0].size(); j++)
		{
			int row_min = 0;
			for (int i = 0; i < matrix.size(); i++)
			{

				if (matrix[i][j] > matrix[row_min][j])
				{
					row_min = i;
				}
			}
			r_min[row_min][j] = 1;
		}

		vector<int> res;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (r_min[i][j] && c_max[i][j]) res.push_back(matrix[i][j]);
			}
		}
		return res;

	}
};