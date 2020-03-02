//404. Subarray Sum II
//1. presum(n + 1, 0)
//2. xxxxxxvvvvvvvvvvvxxxxxxxxxxxx
//l                   r                 count += (r - l)

class Solution {
public:
	/**
	 * @param A: An integer array
	 * @param start: An integer
	 * @param end: An integer
	 * @return: the number of possible answer
	 */
	int subarraySumII(vector<int>& A, int start, int end) {
		// write your code here
		if (A.size() == 0) return 0;
		vector<int> presum(A.size() + 1, 0);
		for (int i = 1; i <= A.size(); i++) presum[i] = presum[i - 1] + A[i - 1];
		int count = 0;
		//  xxxxxxvvvvvvxxxxxx
		//        l     r
		int l = 0, r = 0;
		for (int i = 1; i < presum.size(); i++)
		{
			while (l < i && presum[i] - presum[l] > end) l++;
			while (r < i && presum[i] - presum[r] >= start) r++;
			count += (r - l);
		}
		return count;
	}
};