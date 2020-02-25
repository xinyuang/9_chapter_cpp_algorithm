//397. Longest Continuous Increasing Subsequence
//1. store max_increasing and max_decreasing state
//2. for loop count current increasing decreasing count, update max

class Solution {
public:
	/**
	 * @param A: An array of Integer
	 * @return: an integer
	 */
	int longestIncreasingContinuousSubsequence(vector<int>& A) {
		// write your code here
		if (A.size() == 0) return 0;
		int incre_count = 1, decre_count = 1;
		int max_incre = 1, max_decre = 1;
		for (int i = 1; i < A.size(); i++)
		{
			if (A[i] >= A[i - 1]) {
				incre_count++;
				if (A[i] > A[i - 1])decre_count = 1;
			}
			if (A[i] <= A[i - 1]) {
				decre_count++;
				if (A[i] < A[i - 1]) incre_count = 1;
			}

			max_incre = max(max_incre, incre_count);
			max_decre = max(max_decre, decre_count);
		}
		return max(max_incre, max_decre);
	}
};