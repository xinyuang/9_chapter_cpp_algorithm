//  01 Backpack reverse order
//  complete backpack left to right order
// get the max sum value
class Solution {
public:
	/**
	 * @param m: An integer m denotes the size of a backpack
	 * @param A: Given n items with size A[i]
	 * @return: The maximum size
	 */
	int backPack(int m, vector<int>& A) {
		// write your code here
		vector<bool> dp(m + 1, false);
		dp[0] = true;
		// sort(A.begin(),A.end());  // [2,3,5,7]   [0,1,2,3,4,5,6,7]            [3,4,5,8]   [0,1,2,3,4,5,6,7,8,9,10]
		for (int i = 0; i < A.size(); i++)     //  .   . .                                    .     . . .   . . .
		{
			// allow duplication use normal order
			//  no duplication use reverse order
			for (int j = m; j >= A[i]; j--)
			{

				if (dp[j - A[i]]) dp[j] = true;
			}
		}
		for (int i = m; i >= 0; i--)
		{
			if (dp[i]) return i;
		}
		return 0;
	}
};

class Solution {
public:
	/**
	 * @param m: An integer m denotes the size of a backpack
	 * @param A: Given n items with size A[i]
	 * @return: The maximum size
	 */
	int backPack(int m, vector<int>& A) {
		// write your code here
		vector<int> dp(m + 1, 0);
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = m; j >= A[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
			}
		}
		return dp[m];
	}
};