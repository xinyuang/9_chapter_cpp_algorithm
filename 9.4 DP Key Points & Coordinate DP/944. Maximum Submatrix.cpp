//Maximum Submatrix

class Solution {
public:
	/**
	 * @param matrix: the given matrix
	 * @return: the largest possible sum
	 */
	int maxSubmatrix(vector<vector<int>>& matrix) {
		// write your code here
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
		int res = INT_MIN;
		for (int i = 0; i < matrix.size(); i++)
		{
			vector<int> sum(matrix[0].size(), 0);
			for (int j = i; j < matrix.size(); j++)
			{
				for (int k = 0; k < matrix[0].size(); k++)
				{
					sum[k] += matrix[j][k];
				}
				int subres = findMax(sum);
				res = max(res, subres);
			}
		}
		return res;
	}

	int findMax(vector<int>& sum)
	{
		int res = INT_MIN;
		int presum = 0;

		for (int i = 0; i < sum.size(); i++)
		{
			presum += sum[i];
			res = max(res, presum);
			presum = max(presum, 0);
		}
		return res;
	}
};