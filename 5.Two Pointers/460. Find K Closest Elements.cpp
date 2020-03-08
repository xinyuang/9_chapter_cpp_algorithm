//460. Find K Closest Elements
//1. find closest
//2. two pointer spread to k

class Solution {
public:
	/**
	 * @param A: an integer array
	 * @param target: An integer
	 * @param k: An integer
	 * @return: an integer array
	 */
	vector<int> kClosestNumbers(vector<int>& A, int target, int k) {
		// write your code here
		if (k > A.size() || k == 0) return {};
		int mid = findClosest(A, target);
		int count = 1;
		vector<int> res = { A[mid] };
		int left = mid - 1, right = mid + 1;
		while (count < k)
		{
			if (left >= 0 && right < A.size())
			{
				if (abs(A[left] - target) <= abs(A[right] - target)) res.push_back(A[left--]);
				else res.push_back(A[right++]);
			}
			else if (left < 0 && right < A.size())
			{
				res.push_back(A[right++]);
			}
			else if (right >= A.size() && left >= 0)
			{
				res.push_back(A[left--]);
			}
			count++;
		}
		return res;
	}

	int findClosest(vector<int>& A, int target)
	{
		int left = 0, right = A.size() - 1;
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (A[mid] < target) left = mid;
			else right = mid;
		}
		if (abs(A[left] - target) <= abs(A[right] - target)) return left;
		return right;
	}
};