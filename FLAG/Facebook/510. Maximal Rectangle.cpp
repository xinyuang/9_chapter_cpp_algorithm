//510. Maximal Rectangle
//1. get  height of each line
//2. get max area in each line(monotonic increasing stack)


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
		int g_max = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (i == 0) height[i][j] = matrix[i][j];
				else
				{
					if (matrix[i][j] == 0) height[i][j] = matrix[i][j];
					else height[i][j] = height[i - 1][j] + matrix[i][j];
				}
			}
			int cur_max = getMaxRectangle(height[i]);
			g_max = max(g_max, cur_max);
		}
		return g_max;
	}

	int getMaxRectangle(vector<int>& A)
	{
		int max_area = 0;
		// monotonic increasing stack
		stack<int> stk;
		for (int i = 0; i <= A.size(); i++)
		{
			while (!stk.empty() && (A[stk.top()] > (i == A.size() ? 0 : A[i])))
			{
				int k = stk.top(); stk.pop();
				int l = -1;
				if (!stk.empty()) l = stk.top();
				int cur_area = (i - l - 1) * A[k];
				max_area = max(max_area, cur_area);
			}
			stk.push(i);
		}
		return max_area;
	}
};