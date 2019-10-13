// 654. Sparse Matrix Multiplication

class Solution {
public:
	/**
	 * @param A: a sparse matrix
	 * @param B: a sparse matrix
	 * @return: the result of A * B
	 */
	vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
		// write your code here
		if (A.size() == 0 || A[0].size() == 0 || B.size() == 0 || B[0].size() == 0) return {};
		int na = A.size();
		int ma = A[0].size();
		int nb = B.size();
		int mb = B[0].size();
		vector<vector<int>> res(na, vector<int>(mb, 0));
		for (int i = 0; i < na; i++)
		{
			for (int k = 0; k < ma; k++)
			{
				if (A[i][k] == 0) continue;
				for (int j = 0; j < mb; j++)
				{
					res[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		return res;
	}
};