//676. Decode Ways II
//1. dp(s.size() + 1, 0) dp[0] = 1, dp[1] = 1 or 9
//2. consider 4 situation: nn(0or1L), n * (6or9L), *n(1or2L), **(15L)
//3. stoi(string), '6' istead of 6!

class Solution {
public:
	/**
	 * @param s: a message being encoded
	 * @return: an integer
	 */
	int numDecodings(string& s) {
		// write your code here
		if (s.size() == 0 || s[0] == '0') return 0;
		vector<int> dp(s.size(), 0);
		if (s[0] == '*') dp[0] = 9;
		else dp[0] = 1;
		int prev = 0;
		int mod = pow(10, 9) + 7;
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] != '*')
			{
				if (s[i] != '0') dp[i] = dp[i - 1];
				bool valid = false;
				if (s[i - 1] == '*')
				{
					string c;
					c.assign(1, s[i]);
					if (i == 1) prev = 1;
					else prev = dp[i - 2];
					if (stoi(c) <= 6)
					{
						dp[i] = (dp[i] + 2 * prev) % mod;
					}
					else
					{
						dp[i] = (dp[i] + prev) % mod;
					}
				}
				else if (s[i - 1] != '0' && stoi(s.substr(i - 1, 2)) <= 26) dp[i] = (dp[i] + (i == 1 ? 1 : dp[i - 2])) % mod;
				if (dp[i] == 0) return 0;
			}
			else
			{
				dp[i] = (9L * dp[i - 1]) % mod;
				if (i == 1) prev = 1;
				else prev = dp[i - 2];
				if (s[i - 1] == '1') dp[i] = (dp[i] + prev * 9L) % mod;
				if (s[i - 1] == '2') dp[i] = (dp[i] + prev * 6L) % mod;
				if (s[i - 1] == '*') dp[i] = (dp[i] + prev * 15L) % mod;
			}
		}
		return dp[s.size() - 1];
	}
};