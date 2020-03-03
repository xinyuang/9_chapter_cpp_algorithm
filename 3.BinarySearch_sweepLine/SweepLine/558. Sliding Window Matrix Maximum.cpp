//558. Sliding Window Matrix Maximum
//1. presum[i][j] = presum[i][j - 1] + presum[i - 1][j] + matrix[i - 1][j - 1] - presum[i - 1][j - 1]
//2. max_sum = max(max_sum, presum[i][j] - presum[i][j - k] - presum[i - k][j] + presum[i - k][j - k])

class Solution {
public:
	/**
	 * @param matrix: an integer array of n * m matrix
	 * @param k: An integer
	 * @return: the maximum number
	 */
	int maxSlidingMatrix(vector<vector<int>>& matrix, int k) {
		// write your code here
		if (matrix.size() == 0 || matrix[0].size() == 0 || matrix.size() < k || matrix[0].size() < k) return 0;
		vector<vector<int>> presum(matrix.size() + 1, vector<int>(matrix[0].size(), 0));
		for (int j = 0; j < matrix[0].size(); j++)
		{
			for (int i = 1; i <= matrix.size(); i++)
			{
				presum[i][j] = presum[i - 1][j] + matrix[i - 1][j];
			}
		}
		int max_sum = INT_MIN;
		for (int i = k; i < presum.size(); i++)
		{
			int cur_sum = 0;
			for (int j = 0; j < k; j++)
			{
				cur_sum += (presum[i][j] - presum[i - k][j]);
			}
			max_sum = max(max_sum, cur_sum);
			for (int j = k; j < presum[0].size(); j++)
			{
				cur_sum = cur_sum + (presum[i][j] - presum[i - k][j]) - (presum[i][j - k] - presum[i - k][j - k]);
				max_sum = max(max_sum, cur_sum);
			}
		}
		return max_sum;
	}
};