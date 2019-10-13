// Jump game 2
// minimum steps to reach the last index
class Solution {
public:
	/**
	 * @param A: A list of integers
	 * @return: An integer
	 */
	int jump(vector<int>& A) {              //   idx  [0,1,2,3,4]
		// write your code here                       [2,3,1,1,4]
		if (A.size() == 0) return 0;         //         1 1 1
											//           1 2 2 2
											//             1 2
											//               2 3
		vector<int> dp(A.size(), INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j <= A[i]; j++)
			{
				if (i + j <= A.size()) dp[i + j] = min(dp[i + j], dp[i] + 1);
			}
		}
		return dp.back();
	}
};