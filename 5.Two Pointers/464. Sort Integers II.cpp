class Solution {
public:
	/**
	 * @param A: an integer array
	 * @return: nothing
	 */
	void sortIntegers2(vector<int>& A) {
		// write your code here
		quickSort(A, 0, A.size() - 1);
	}

	void quickSort(vector<int>& A, int start, int end)
	{
		if (start >= end) return;
		int small = start, smallSeeker = start + 1;
		while (smallSeeker <= end)
		{
			if (A[smallSeeker] < A[start])
			{
				small++;
				swap(A, small, smallSeeker);
			}
			smallSeeker++;
		}
		swap(A, small, start);

		quickSort(A, start, small);
		quickSort(A, small + 1, end);
	}

	void swap(vector<int>& A, int a, int b)
	{
		int tmp = A[a];
		A[a] = A[b];
		A[b] = tmp;
	}
};