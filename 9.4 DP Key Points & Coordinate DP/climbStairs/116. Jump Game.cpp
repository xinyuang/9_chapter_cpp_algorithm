// Jump game
// able to reach the last index
// [2,3,1,1,4]
//  . . . . .
class Solution {
public:
	/**
	 * @param A: A list of integers
	 * @return: A boolean
	 */
	bool canJump(vector<int>& A) {
		// write your code here
		if (A.size() == 0) return false;
		vector<bool> dp(A.size(), false);
		dp[0] = true;
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j <= A[i]; j++)
			{
				if (dp[i] && i + j < A.size()) dp[i + j] = true;
			}
		}
		return dp.back();
	}
};