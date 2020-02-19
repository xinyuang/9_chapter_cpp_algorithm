//130. Heapify
//1. iterate from end to begin
//2. son = idx min(A[2 * k + 1], A[2 * k + 2]), if son smaller swap k and son, else break

class Solution {
public:
	/*
	 * @param A: Given an integer array
	 * @return: nothing
	 */
	void heapify(vector<int>& A) {
		// write your code here
		for (int i = A.size() - 1; i >= 0; i--)
		{
			siftdown(A, i);
		}
	}

	void siftdown(vector<int>& A, int k)
	{
		while (2 * k + 1 < A.size())
		{
			int son = 2 * k + 1;
			if (2 * k + 2 < A.size() && A[2 * k + 2] < A[son])
			{
				son = 2 * k + 2;
			}
			if (A[son] >= A[k]) break;
			swap(A, k, son);
			k = son;
		}
	}

	void swap(vector<int>& A, int a, int b)
	{
		int tmp = A[a];
		A[a] = A[b];
		A[b] = tmp;
	}
};