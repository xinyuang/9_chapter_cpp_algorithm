//640. One Edit Distance
//1. set m > n, check abs(m - n) > 1 return false
//2. if (s[i] != t[i]) return s.susbtr(i + 1) == t.substr(i) or s.substr(i + 1) == t.substr(i + 1)

class Solution {
public:
	/**
	 * @param s: a string
	 * @param t: a string
	 * @return: true if they are both one edit distance apart or false
	 */
	bool isOneEditDistance(string& s, string& t) {
		// write your code here
		int m = s.size();
		int n = t.size();
		// always set s.size() >= t.size()
		if (abs(m - n) > 1 || s == t) return false;
		if (m < n) return isOneEditDistance(t, s);
		for (int i = 0; i < n; i++)
		{
			if (s[i] != t[i])
			{
				if (n == m)
				{
					return s.substr(i + 1) == t.substr(i + 1);
				}
				return s.substr(i + 1) == t.substr(i);
			}
		}
		return m != n;
	}
};