// O( log(m+n) )
// [2,3,4,6,7,7,8]     7
//      .                           => (7+5)/2 = 6     A[ a_st + k/2 - 1] < B[ b_st + k/2 - 1] ?
// [4,5,6,7,8]         5                               delete the smaller part
//      .
class Solution {
public:
	/*
	 * @param A: An integer array
	 * @param B: An integer array
	 * @return: a double whose format is *.5 or *.0
	 */
	double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
		// write your code here
		vector<int> a = A;
		vector<int> b = B;
		int n = a.size() + b.size();
		if (n % 2 == 0) return (findKth(a, 0, b, 0, n / 2) + findKth(a, 0, b, 0, n / 2 + 1)) / 2.0;
		return findKth(a, 0, b, 0, n / 2 + 1);
	}

	int findKth(vector<int>& a, int a_start, vector<int>& b, int b_start, int k)
	{
		if (a_start >= a.size()) return b[b_start + k - 1];
		if (b_start >= b.size()) return a[a_start + k - 1];
		if (k == 1)
		{
			return min(a[a_start], b[b_start]);
		}
		int a_new_start = (a_start + k / 2 - 1 < a.size()) ? a[a_start + k / 2 - 1] : INT_MAX;
		int b_new_start = (b_start + k / 2 - 1 < b.size()) ? b[b_start + k / 2 - 1] : INT_MAX;
		if (a_new_start < b_new_start) return findKth(a, a_start + k / 2, b, b_start, k - k / 2);
		else return findKth(a, a_start, b, b_start + k / 2, k - k / 2);
	}
};