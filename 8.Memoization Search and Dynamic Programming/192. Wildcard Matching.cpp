// Wildcard matching
// devide and conquer
// current match ? next match?
class Solution {
public:
	/**
	 * @param s: A string
	 * @param p: A string includes "?" and "*"
	 * @return: is Match?
	 */
	bool isMatch(string& s, string& p) {
		// write your code here
		//           stringlistesfe   st*l.st   stri*ngl.st
		//               .      .       .         .
		//    1. "*"
		//       a. nothing to Match
		//       b. match several 
		//    2. !"*"
		vector<vector<int>> memo(s.size(), vector<int>(p.size(), -1));
		bool res = search(s, 0, p, 0, memo);
		return res;
	}

	bool search(string& s, int s_idx, string& p, int p_idx, vector<vector<int>>& memo)
	{
		//  aa   a******

		if (s.size() == s_idx)
		{
			for (int i = p_idx; i < p.size(); i++)
			{
				if (p[i] != '*') return false;
			}
			return true;
		}
		//  aaaaaaaa  ab
		if (p.size() == p_idx) return false;
		if (memo[s_idx][p_idx] != -1) return memo[s_idx][p_idx];

		//    aaab *b      ab  *ab
		if (p[p_idx] == '*')
		{
			bool zero = search(s, s_idx, p, p_idx + 1, memo);
			bool one = search(s, s_idx + 1, p, p_idx, memo);
			memo[s_idx][p_idx] = zero || one;
			return zero || one;
		}
		else
		{
			bool matched = p[p_idx] == '?' || p[p_idx] == s[s_idx];
			bool next = search(s, s_idx + 1, p, p_idx + 1, memo);
			memo[s_idx][p_idx] = matched && next;
			return matched && next;
		}
	}
};

class Solution {
public:
	/**
	 * @param s: A string
	 * @param p: A string includes "?" and "*"
	 * @return: is Match?
	 */
	bool isMatch(string& s, string& p) {
		// write your code here
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= s.size(); i++)
		{
			dp[i][0] = false;
		}
		for (int j = 1; j <= p.size(); j++)
		{
			dp[0][j] = dp[0][j - 1] && (p[j - 1] == '*');
		}
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = 1; j <= p.size(); j++)
			{
				if (p[j - 1] == '*')
				{
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				}
				else if (p[j - 1] == '?') {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
				}
			}
		}
		return dp[s.size()][p.size()];
	}
};