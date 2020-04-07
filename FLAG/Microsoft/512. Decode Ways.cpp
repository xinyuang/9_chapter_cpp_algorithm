//512. Decode Ways


class Solution {
public:
	/**
	 * @param s: a string,  encoded message
	 * @return: an integer, the number of ways decoding
	 */
	int numDecodings(string& s) {
		// write your code here
		vector<int> dp(s.size() + 1, 0);
		if (s.size() == 0 || s[0] == '0') return 0;
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] != '0') dp[i + 1] = dp[i];
			int cur = atoi(s.substr(i - 1, 2).c_str());
			if (cur <= 26 && cur >= 10) dp[i + 1] += dp[i - 1];
			if (dp[i + 1] == 0) return 0;
		}
		return dp.back();
	}
};