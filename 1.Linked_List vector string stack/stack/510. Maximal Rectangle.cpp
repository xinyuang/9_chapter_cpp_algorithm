//510. Maximal Rectangle
//1. dp store height
//2. monotonic stack calculate max_area of current line

class Solution {
public:
	/**
	 * @param matrix: a boolean 2D matrix
	 * @return: an integer
	 */
	int maximalRectangle(vector<vector<bool>>& matrix) {
		// write your code here
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
		vector<vector<int>> height(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix[0].size(); i++) height[0][i] = matrix[0][i];
		for (int i = 1; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j])
				{
					height[i][j] = height[i - 1][j] + 1;
				}
			}
		}
		int max_area = 0;
		for (int r = 0; r < matrix.size(); r++)
		{
			stack<int> stk;
			for (int i = 0; i <= matrix[0].size(); i++)
			{
				while (!stk.empty() && (height[r][stk.top()] > (i == matrix[0].size() ? 0 : height[r][i])))
				{
					int k = stk.top(); stk.pop();
					int j = -1;
					if (!stk.empty()) j = stk.top();
					int cur_area = (i - j - 1) * height[r][k];
					max_area = max(max_area, cur_area);
				}
				stk.push(i);
			}
		}
		return max_area;
	}
};