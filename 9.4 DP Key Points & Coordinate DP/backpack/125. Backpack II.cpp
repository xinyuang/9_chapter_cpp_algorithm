//125. Backpack II
// Input: m = 5, A = [1, 3, 4, 2], V = [1, 5, 2, 4]
// Output:          [0,  1,  2,  3,  4,  5]
//                   .   .   .   .   .   .  
//                   0   1   4   5   2   2+1 4+5 1+2 5+4
class Solution {
public:
	/**
	 * @param m: An integer m denotes the size of a backpack
	 * @param A: Given n items with size A[i]
	 * @param V: Given n items with value V[i]
	 * @return: The maximum value
	 */
	int backPackII(int m, vector<int>& A, vector<int>& V) {
		// write your code here
		vector<int> dp(m + 1, 0);
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = m; j >= A[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
			}
		}
		return dp[m];
	}
};

class Solution {
public:
	/**
	 * @param m: An integer m denotes the size of a backpack
	 * @param A: Given n items with size A[i]
	 * @param V: Given n items with value V[i]
	 * @return: The maximum value
	 */
	int backPackII(int m, vector<int>& A, vector<int>& V) {
		// write your code here
		int dp[A.size() + 1][m + 1] = { 0 };
		for (int i = 0; i <= A.size(); i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0 || j == 0) {
					dp[i][j] = 0;
				}
				else if (A[i - 1] > j) {
					dp[i][j] = dp[(i - 1)][j];
				}
				else {
					dp[i][j] = max(dp[(i - 1)][j], dp[(i - 1)][j - A[i - 1]] + V[i - 1]);
				}
			}
		}
		return dp[A.size()][m];
	}
};