// Regular Expression Matching
// devide and conquer
// memo[i][j] means s[i] p[j] is matched
class Solution {
public:
	/**
	 * @param s: A string
	 * @param p: A string includes "." and "*"
	 * @return: A boolean
	 */
	bool isMatch(string& s, string& p) {
		// write your code here
		vector<vector<int>> memo(s.size(), vector<int>(p.size(), -1));
		bool res = search(s, 0, p, 0, memo);
		return res;
	}

	bool search(string& s, int s_idx, string& p, int p_idx, vector<vector<int>>& memo)
	{
		//  aa   a******

		if (s.size() == s_idx)
		{
			int remain = p.size() - p_idx;
			if (remain % 2) return false;
			while (p_idx < p.size() - 1)
			{
				if (p[p_idx + 1] != '*') return false;
				p_idx += 2;
			}
			return true;
		}
		//  aaaaaaaa  ab
		if (p.size() == p_idx) return false;
		if (memo[s_idx][p_idx] != -1) return memo[s_idx][p_idx];

		//    aaab a*b      ab  c*ab
		if (p[p_idx + 1] == '*')
		{
			bool zero = search(s, s_idx, p, p_idx + 2, memo);
			bool one = (p[p_idx] == '.' || p[p_idx] == s[s_idx]) && search(s, s_idx + 1, p, p_idx, memo);
			memo[s_idx][p_idx] = zero || one;
			return zero || one;
		}
		else
		{
			bool matched = p[p_idx] == '.' || p[p_idx] == s[s_idx];
			bool next = search(s, s_idx + 1, p, p_idx + 1, memo);
			memo[s_idx][p_idx] = matched && next;
			return matched && next;
		}
	}
};