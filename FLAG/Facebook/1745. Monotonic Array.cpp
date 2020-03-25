1745. Monotonic Array

class Solution {
public:
	/**
	 * @param A: a array
	 * @return: is it monotonous
	 */
	bool isMonotonic(vector<int>& A) {
		// Write your code here.
		bool incre = true;
		bool decre = true;
		for (int i = 1; i < A.size(); i++)
		{
			if (A[i] > A[i - 1]) decre = false;
			if (A[i] < A[i - 1]) incre = false;
		}
		return incre || decre;
	}
};