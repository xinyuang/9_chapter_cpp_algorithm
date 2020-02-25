//436. Maximal Square
//1. init dp = matrix, max_len = max(first row, first column element)
//2. dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1
//3. return max(dp[i][j] * dp[i][j])  longest square length

class Solution {
public:
	/**
	 * @param matrix: a matrix of 0 and 1
	 * @return: an integer
	 */
	int maxSquare(vector<vector<int>>& matrix) {
		// write your code here
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
		int max_len = 0;
		for (int i = 0; i < matrix.size(); i++) {
			dp[i][0] = matrix[i][0];
			max_len = max(max_len, dp[i][0]);
		}
		for (int j = 0; j < matrix[0].size(); j++) {
			dp[0][j] = matrix[0][j];
			max_len = max(max_len, dp[0][j]);
		}
		for (int i = 1; i < matrix.size(); i++)
		{
			for (int j = 1; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == 1) dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				max_len = max(max_len, dp[i][j]);
			}
		}
		return max_len * max_len;
	}
};