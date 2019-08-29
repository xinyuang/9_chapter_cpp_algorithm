class Solution {
public:
	/**
	 * @param s: A string
	 * @param p: A string includes "." and "*"
	 * @return: A boolean
	 */
	bool isMatch(string& s, string& p) {
		// write your code here
		if (p.size() == 0) return false;
		vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
		bool res = matching(s, 0, p, 0, dp);
		return res;
	}

	bool matching(string& s, int s_idx, string& p, int p_idx, vector<vector<int>>& dp)
	{
		if (s.size() == s_idx)
		{
			if ((p.size() - p_idx) % 2 != 0) return false;
			for (int i = p_idx; i < p.size() - 1; i += 2)
			{
				if (p[p_idx + 1] != '*') return false;
			}
			return true;
		}
		if (p.size() == p_idx) return false;
		if (dp[s_idx][p_idx] != -1) return dp[s_idx][p_idx];
		if (p.size() - p_idx >= 2 && p[p_idx + 1] == '*')
		{
			bool zero = matching(s, s_idx, p, p_idx + 2, dp);
			bool one = (s[s_idx] == p[p_idx] || p[p_idx] == '.') && matching(s, s_idx + 1, p, p_idx, dp);
			dp[s_idx][p_idx] = zero || one;
			return zero || one;
		}
		else
		{
			bool matched = (s[s_idx] == p[p_idx] || p[p_idx] == '.');
			bool next = matching(s, s_idx + 1, p, p_idx + 1, dp);
			dp[s_idx][p_idx] = matched && next;
			return matched && next;
		}
	}
};