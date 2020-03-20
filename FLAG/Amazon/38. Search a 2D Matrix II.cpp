//38. Search a 2D Matrix II
//1. from left bottom to right top
//2. since no duplicate, find target, row--, col++

class Solution {
public:
	/**
	 * @param matrix: A list of lists of integers
	 * @param target: An integer you want to search in matrix
	 * @return: An integer indicate the total occurrence of target in the given matrix
	 */
	int searchMatrix(vector<vector<int>>& matrix, int target) {
		// write your code here
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
		int row = matrix.size() - 1;
		int count = 0;
		for (int col = 0; col < matrix[0].size(); col++)
		{
			while (row >= 0 && matrix[row][col] > target) row--;
			if (row >= 0 && matrix[row][col] == target) count++;
		}
		return count;
	}
};


class Solution {
public:
	/**
	 * @param matrix: A list of lists of integers
	 * @param target: An integer you want to search in matrix
	 * @return: An integer indicate the total occurrence of target in the given matrix
	 */
	int searchMatrix(vector<vector<int>>& matrix, int target) {
		// write your code here
		int row = matrix.size() - 1;
		int col = 0;
		int count = 0;
		while (col < matrix[0].size() && row >= 0)
		{
			while (row >= 0 && matrix[row][col] > target)
			{
				row--;
			}
			if (col < matrix[0].size() && row >= 0 && matrix[row][col] == target) count++;
			col++;
		}
		return count;
	}
};