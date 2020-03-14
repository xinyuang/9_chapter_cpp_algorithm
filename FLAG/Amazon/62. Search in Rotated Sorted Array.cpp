//62. Search in Rotated Sorted Array
//      /
//     /
//    /
//        /
//       /
//1. if (A[left] < A[right]) binary search
//2. mid = (right - left) / 2 + left, find first half and second half, return idx

class Solution {
public:
	/**
	 * @param A: an integer rotated sorted array
	 * @param target: an integer to be searched
	 * @return: an integer
	 */
	int search(vector<int>& A, int target) {
		// write your code here
		if (A.size() == 0) return -1;
		int res = findTarget(0, A.size() - 1, target, A);
		return res;
	}

	int findTarget(int start, int end, int target, vector<int>& A)
	{
		if (start >= end) {
			if (A[start] == target) return start;
			return -1;
		}
		if (A[start] < A[end]) return binarySearch(start, end, target, A);
		else
		{
			int mid = (end - start) / 2 + start;
			int left = findTarget(start, mid, target, A);
			if (left == -1) return findTarget(mid + 1, end, target, A);
			else return left;
		}
	}

	int binarySearch(int start, int end, int target, vector<int>& A)
	{
		int left = start, right = end;
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (A[mid] < target) left = mid;
			else right = mid;
		}
		if (A[left] == target) return left;
		if (A[right] == target) return right;
		return -1;
	}
};


class Solution {
public:
	/**
	 * @param A: an integer rotated sorted array
	 * @param target: an integer to be searched
	 * @return: an integer
	 */
	int search(vector<int>& A, int target) {
		// write your code here
		if (A.size() == 0) return -1;
		int left = 0, right = A.size() - 1;
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (A[mid] > A[left])
			{
				if (target >= A[left] && A[mid] >= target)
				{
					right = mid;
				}
				else left = mid;
			}
			else
			{
				if (target <= A[right] && A[mid] <= target)
				{
					left = mid;
				}
				else right = mid;
			}
		}
		if (A[left] == target) return left;
		if (A[right] == target) return right;
		return -1;
	}
};