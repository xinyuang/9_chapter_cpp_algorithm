154. Regular Expression Matching

class Solution {
public:
	/**
	 * @param s: A string
	 * @param p: A string includes "." and "*"
	 * @return: A boolean
	 */
	bool isMatch(string& s, string& p) {
		// write your code here
		vector<vector<int>> dp(p.size() + 1, vector<int>(s.size() + 1, 0));
		dp[0][0] = 1;
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == '*' && i >= 1) dp[i + 1][0] = dp[i - 1][0];
		}
		for (int i = 0; i < p.size(); i++)
		{
			for (int j = 0; j < s.size(); j++)
			{
				if (p[i] == s[j] || p[i] == '.') dp[i + 1][j + 1] = dp[i][j];
				else
				{
					if (p[i] == '*')
					{
						//    i
						//  ab*

						//  abbbb
						//      j
						if (i != 0 && (p[i - 1] == s[j] || p[i - 1] == '.') && dp[i + 1][j]) dp[i + 1][j + 1] = 1;
						//     i
						//  aab*c
						//  aac
						//   j
						if (i >= 1 && dp[i - 1][j + 1]) dp[i + 1][j + 1] = 1;
					}
				}
			}
		}
		return dp[p.size()][s.size()];
	}
};