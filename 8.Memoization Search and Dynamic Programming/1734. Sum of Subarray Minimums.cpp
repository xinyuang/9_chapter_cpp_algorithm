
//monotonic stack

class Solution {
public:
	/**
	 * @param A: an array
	 * @return: the sum of subarray minimums
	 */
	int sumSubarrayMins(vector<int>& A) {
		// Write your code here.
		stack<int> stk;
		int res = 0;
		int mod = pow(10, 9) + 7;
		for (int i = 0; i <= A.size(); i++)
		{
			while (!stk.empty() && A[stk.top()] > (i == A.size() ? 0 : A[i]))
			{
				int j = stk.top();
				stk.pop();
				int k;
				if (stk.empty()) k = -1;
				else k = stk.top();
				res = (res + A[j] * (i - j) * (j - k)) % mod;
			}
			stk.push(i);
		}
		return res;
	}
};

// dynamic programming
class Solution {
public:
	/**
	 * @param A: an array
	 * @return: the sum of subarray minimums
	 */
	int sumSubarrayMins(vector<int>& A) {
		// Write your code here.
		stack<int> s;
		s.push(-1);
		int res = 0;
		int mod = pow(10, 9) + 7;
		vector<int> dp(A.size() + 1, 0);
		for (int i = 0; i < A.size(); i++)
		{
			while (s.top() != -1 && A[s.top()] > A[i])
			{
				s.pop();
			}
			dp[i + 1] = dp[s.top() + 1] + (i - s.top()) * A[i];
			s.push(i);
			res = (res + dp[i + 1]) % mod;
		}
		return res;
	}
};