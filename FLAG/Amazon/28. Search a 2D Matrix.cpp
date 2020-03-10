//28. Search a 2D Matrix
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.

class Solution {
public:
	/**
	 * @param matrix: matrix, a list of lists of integers
	 * @param target: An integer
	 * @return: a boolean, indicate whether matrix contains target
	 */
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		// write your code here
		bool res = false;
		int m = matrix.size();
		if (m == 0) return res;
		int n = matrix[0].size();
		if (n == 0) return res;

		int len = m * n;
		int mid = 0;
		int left = 0;
		int right = len - 1;
		while (left + 1 < right)
		{
			mid = (right - left) / 2 + left;
			int row = mid / n;
			int col = mid % n;
			if (matrix[row][col] > target) right = mid;
			if (matrix[row][col] < target) left = mid;
			if (matrix[row][col] == target) return true;
		}

		if (matrix[left / n][left % n] == target) return true;
		if (matrix[right / n][right % n] == target) return true;

		return false;

	}
};
