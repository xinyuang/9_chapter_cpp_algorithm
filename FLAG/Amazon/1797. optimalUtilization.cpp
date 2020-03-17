//1797. optimalUtilization
//two pointer
//for loop A, while ptr-- B

class Solution {
public:
	/**
	 * @param A: a integer sorted array
	 * @param B: a integer sorted array
	 * @param K: a integer
	 * @return: return a pair of index
	 */
	vector<int> optimalUtilization(vector<int>& A, vector<int>& B, int K) {
		// write your code here
		int left = 0, right = B.size() - 1;
		int min_diff = INT_MAX;
		if (A.size() == 0 || B.size() == 0) return {};
		vector<int> res = { -1,-1 };
		for (int left = 0; left < A.size(); left++)
		{
			while (right > 0 && A[left] + B[right] > K) right--;
			while (right > 0 && B[right] == B[right - 1]) right--;
			if (abs(K - A[left] - B[right]) < min_diff)
			{
				res[0] = left;
				res[1] = right;
				min_diff = K - A[left] - B[right];
				if (min_diff == 0) return res;
			}
		}
		return res;
	}
};