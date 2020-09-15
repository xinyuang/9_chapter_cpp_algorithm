//193. Longest Valid Parentheses
//1. (())))))()()
//2. ((((((()(((((((()

// dp[i] is s.substr(i) longest valid length
// if dp[i] == ')' skip
// if dp[i] == '(' check dp[i+1] + 2 plus dp[idx] where the first idx after the symmetric ')'

class Solution {
public:
	/**
	 * @param s: a string
	 * @return: return a integer
	 */
	int longestValidParentheses(string& s) {
		// write your code here
		vector<int> dp(s.size(), 0);
		int max_len = 0;
		for (int i = s.size() - 2; i >= 0; i--)
		{
			if (s[i] == '(')
			{
				int j = i + dp[i + 1] + 1;
				if (s[j] == ')')
				{
					dp[i] = dp[i + 1] + 2;
					if (j + 1 < s.size())
					{
						dp[i] += dp[j + 1];
					}
				}
			}
			max_len = max(max_len, dp[i]);
		}
		return max_len;
	}
};

class Solution {
public:
	/**
	 * @param s: a string
	 * @return: return a integer
	 */
	int longestValidParentheses(string& s) {
		// write your code here
		stack<int> stk;
		int ttl_len = 0;
		int max_len = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(') stk.push(i);
			else {
				if (stk.empty()) ttl_len = 0;
				else {
					int idx = stk.top(); stk.pop();
					int cur_len = (i - idx + 1);
					if (stk.empty()) {
						ttl_len += cur_len;
						cur_len = ttl_len;
					}
					else {
						cur_len = (i - stk.top());
					}
					max_len = max(max_len, cur_len);
				}

			}
		}
		return max_len;
	}
};

