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