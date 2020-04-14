//65. Median of two Sorted Arrays
//1. brute force merge sort

class Solution {
public:
	/*
	 * @param A: An integer array
	 * @param B: An integer array
	 * @return: a double whose format is *.5 or *.0
	 */
	double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
		// write your code here
		int a_ptr = 0, b_ptr = 0;
		int tar = (A.size() + B.size()) / 2;
		bool two = ((A.size() + B.size()) % 2 == 0);
		int count = 0;
		vector<int> res = { -1,-1 };
		int median = -1;
		while (count < tar + 1)
		{
			if (a_ptr < A.size() && b_ptr < B.size())
			{
				if (A[a_ptr] < B[b_ptr]) {
					res[1] = median;
					res[0] = A[a_ptr];
					median = A[a_ptr];
					a_ptr++;
				}
				else {
					res[1] = median;
					res[0] = B[b_ptr];
					median = B[b_ptr];
					b_ptr++;
				}
			}
			else if (a_ptr < A.size())
			{
				res[1] = median;
				res[0] = A[a_ptr];
				median = A[a_ptr];
				a_ptr++;
			}
			else {
				res[1] = median;
				res[0] = B[b_ptr];
				median = B[b_ptr];
				b_ptr++;
			}
			count++;
		}
		if (two)
		{
			return (double)(res[0] + res[1]) / 2.0;
		}
		return res[0];
	}
};