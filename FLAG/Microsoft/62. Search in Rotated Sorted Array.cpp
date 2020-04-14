//62. Search in Rotated Sorted Array

// chunck to 4 situations

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
			if (A[mid] > A[0])
			{
				if (A[mid] > target && target >= A[0]) right = mid;
				else left = mid;
			}
			else
			{
				if (A[mid] < target && target < A[0]) left = mid;
				else right = mid;
			}
		}
		if (A[left] == target) return left;
		if (A[right] == target) return right;
		return -1;
	}
};

//part 1 funct 1 to process monotonic increasing, part 2 recursively process rotated array
class Solution {
public:
	/**
	 * @param A: an integer rotated sorted array
	 * @param target: an integer to be searched
	 * @return: an integer
	 */
	int search(vector<int>& A, int target) {
		// write your code here
		int res = findTarget(A, 0, A.size() - 1, target);
		return res;
	}

	int findTarget(vector<int>& A, int start, int end, int target)
	{
		if (start > end) return -1;
		if (start == end)
		{
			if (A[start] == target) return start;
			return -1;
		}
		int mid = (end - start) / 2 + start;
		int res = -1;
		if (A[start] < A[mid])
		{
			res = find(A, start, mid, target);
			if (res == -1) return findTarget(A, mid, end, target);
		}
		else
		{
			res = find(A, mid, end, target);
			if (res == -1) return findTarget(A, start, mid, target);
		}
		return res;
	}

	int find(vector<int>& A, int start, int end, int target)
	{
		if (start > end) return -1;
		while (start + 1 < end)
		{
			int mid = (end - start) / 2 + start;
			if (A[mid] > target) end = mid;
			else start = mid;
		}
		if (A[start] == target) return start;
		if (A[end] == target) return end;
		return -1;
	}
};