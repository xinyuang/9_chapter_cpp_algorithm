/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


// Interval Sum
class Solution {
public:
	/**
	 * @param A: An integer list
	 * @param queries: An query list
	 * @return: The result list
	 */
	vector<long long> intervalSum(vector<int>& A, vector<Interval>& queries) {
		// write your code here
		vector<int> dp(A.size() + 1, 0);
		initPresum(dp, A);
		vector<long long> res;
		for (int i = 0; i < queries.size(); i++)
		{
			res.push_back(dp[queries[i].end + 1] - dp[queries[i].start]);
		}
		return res;
	}

	void initPresum(vector<int>& dp, vector<int>& A)
	{
		for (int i = 0; i < A.size(); i++)
		{
			dp[i + 1] = dp[i] + A[i];
		}
	}
};