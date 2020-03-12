//34. N - Queens II
//1. dfs path vector < int>
//2. r + c, r - c, c == col check attack

class Solution {
public:
	/**
	 * @param n: The number of queens.
	 * @return: The total number of distinct solutions.
	 */
	int totalNQueens(int n) {
		// write your code here
		int res = 0;
		vector<int> col;
		findNQueens(res, col, n);
		return res;
	}

	void findNQueens(int& res, vector<int>& col, int n)
	{
		if (col.size() == n)
		{
			res++;
			return;
		}
		for (int i = 0; i < n; i++)
		{
			if (!is_valid(col, n, i)) continue;
			col.push_back(i);
			findNQueens(res, col, n);
			col.pop_back();
		}
	}

	bool is_valid(vector<int>& cols, int n, int c)
	{
		int r = cols.size();
		for (int i = 0; i < cols.size(); i++)
		{
			int row = i;
			int col = cols[i];
			if (c == col || r + c == col + row || r - c == row - col) return false;
		}
		return true;
	}
};