//75. Find Peak Element
//if (A[mid] < A[mid + 1]) left = mid;
//else right = mid;

class Solution {
public:
	/**
	 * @param A: An integers array.
	 * @return: return any of peek positions.
	 */
	int findPeak(vector<int>& A) {
		// write your code here
		int left = 1, right = A.size() - 2;
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (A[mid] < A[mid + 1]) left = mid;
			else right = mid;
		}
		if (A[left] > A[left - 1] && A[left] > A[left + 1])return left;
		return right;
	}
};