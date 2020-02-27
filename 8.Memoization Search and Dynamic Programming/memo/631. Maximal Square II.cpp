631. Maximal Square II
1. up triagle, down triangle, diag[i][j]
2. cur = min(min(up[i - 1][j], down[i][j - 1]), diag[i - 1][j - 1])
3. res == 1 ? res = max(cur + 1, res);


class Solution {
public:
	/**
	 * @param matrix: a matrix of 0 an 1
	 * @return: an integer
	 */
	int maxSquare2(vector<vector<int>>& matrix) {
		// write your code here
		vector<vector<int>> up(matrix.size(), vector<int>(matrix[0].size(), 0));
		vector<vector<int>> down(matrix.size(), vector<int>(matrix[0].size(), 0));
		vector<vector<int>> diag(matrix.size(), vector<int>(matrix[0].size(), 0));
		vector<vector<int>> square(matrix.size(), vector<int>(matrix[0].size(), 0));
		int res = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			res = max(res, square[i][0]);
			up[i][0] = !matrix[i][0];
			down[i][0] = !matrix[i][0];
			diag[i][0] = matrix[i][0];
			square[i][0] = matrix[i][0];
		}
		for (int i = 0; i < matrix[0].size(); i++)
		{
			up[0][i] = !matrix[0][i];
			down[0][i] = !matrix[0][i];
			diag[0][i] = matrix[0][i];
			square[0][i] = matrix[0][i];
			res = max(res, square[0][i]);
		}
		for (int i = 1; i < matrix.size(); i++)
		{
			for (int j = 1; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == 0) up[i][j] = min(up[i - 1][j - 1], up[i - 1][j]) + 1;
				if (matrix[i][j] == 0) down[i][j] = min(down[i][j - 1], down[i - 1][j - 1]) + 1;
				if (matrix[i][j] == 1) diag[i][j] = diag[i - 1][j - 1] + 1;
				if (matrix[i][j] == 1) square[i][j] = min(min(up[i - 1][j], down[i][j - 1]), diag[i - 1][j - 1]) + 1;
				res = max(res, square[i][j]);
			}
		}
		return res * res;
	}
};