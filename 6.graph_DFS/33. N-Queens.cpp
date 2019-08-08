class Solution {
public:
	/*
	 * @param n: The number of queens
	 * @return: All distinct solutions
	 */
	vector<vector<string>> solveNQueens(int n) {
		// write your code here
		vector<int> cols;
		vector<vector<string>> res;
		backtrack(n, cols, res);
		return res;
	}

	void backtrack(int n, vector<int>& cols, vector<vector<string>>& res)
	{
		if (cols.size() == n)
		{
			vector<string> ans = draw_chaseboard(cols);
			res.push_back(ans);
			return;
		}

		int row = cols.size();
		for (int i = 0; i < n; i++)
		{
			int col = i;
			if (!is_valid(cols, row, col)) continue;
			cols.push_back(col);
			backtrack(n, cols, res);
			cols.pop_back();
		}
	}

	vector<string> draw_chaseboard(vector<int>& cols)
	{
		vector<string> res;
		for (int i = 0; i < cols.size(); i++)
		{
			string str = "";
			for (int j = 0; j < cols.size(); j++)
			{
				if (cols[i] == j) str += "Q";
				else str += ".";
			}
			res.push_back(str);
		}
		return res;
	}

	bool is_valid(vector<int>& cols, int row, int col)
	{
		for (int i = 0; i < cols.size(); i++)
		{
			int r = i;
			int c = cols[i];
			if (col == c) return false;
			if (r - c == row - col || r + c == row + col)
			{
				return false;
			}
		}
		return true;
	}
};