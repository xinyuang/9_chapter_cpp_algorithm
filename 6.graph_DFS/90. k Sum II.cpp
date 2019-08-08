class Solution {
public:
	/*
	 * @param A: an integer array
	 * @param k: a postive integer <= length(A)
	 * @param target: an integer
	 * @return: A list of lists of integer
	 */
	vector<vector<int>> kSumII(vector<int>& A, int k, int target) {
		// write your code here
		vector<vector<int>> res;
		vector<int> com;
		sort(A.begin(), A.end());
		helper(A, k, target, com, res, 0);
		return res;
	}

	void helper(vector<int>& A, int k, int target, vector<int>& com, vector<vector<int>>& res, int start)
	{
		if (com.size() == k)
		{
			if (target == 0) res.push_back(com);
			return;
		}

		for (int i = start; i < A.size(); i++)
		{
			com.push_back(A[i]);
			helper(A, k, target - A[i], com, res, i + 1);
			com.pop_back();
		}
	}
};