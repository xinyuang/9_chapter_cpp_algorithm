//390. Find Peak Element II
//
//1. set column left, right, binary search, make left right converge
//2. when mid updated, find max element in mid column, go left or right
//3. the new colMax is larger than neighbor colMax, in the end, find the peak

class Solution {
public:
	/*
	 * @param A: An integer matrix
	 * @return: The index of the peak
	 */
	vector<int> findPeakII(vector<vector<int>>& A) {
		// write your code here
		if (A.size() == 0 || A[0].size() == 0) return {};
		int left = 1, right = A[0].size() - 1;
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			int row = findColMax(mid, A);
			if (A[row][mid - 1] > A[row][mid]) right = mid;
			else if (A[row][mid + 1] > A[row][mid]) left = mid;
			else return { row,mid };
		}
		int row = findColMax(left, A);
		if (A[row][left] > A[row][left - 1] && A[row][left] > A[row][left + 1]) return { row,left };
		row = findColMax(right, A);
		return { row,right };
	}

	int findColMax(int col, vector<vector<int>>& A)
	{
		int row = 0;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i][col] > A[row][col]) row = i;
		}
		return row;
	}
};