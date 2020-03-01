//405. Submatrix Sum
//
//1. set row anchor, scan submatrix, calculate columnSum
//2. for loop columnSum, get the presum of the submatrix
//3. use unordered_map to record idx, when cur presum is same as previous, submatrix sum = 0

class Solution {
public:
	/*
	 * @param matrix: an integer matrix
	 * @return: the coordinate of the left-up and right-down number
	 */
	vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
		// write your code here
		for (int i = 0; i < matrix.size(); i++)
		{
			vector<int> columnSum(matrix[0].size(), 0);
			for (int j = i; j < matrix.size(); j++)
			{
				for (int k = 0; k < matrix[0].size(); k++)
				{
					columnSum[k] += matrix[j][k];
				}
				unordered_map<int, int> mp;
				int presum = 0;
				for (int m = 0; m < matrix[0].size(); m++)
				{
					presum += columnSum[m];
					if (presum == 0) return { {i,0},{j,m} };
					if (mp.count(presum)) return { {i,mp[presum] + 1},{j,m} };
					mp[presum] = m;
				}
			}
		}
		return {};
	}
};