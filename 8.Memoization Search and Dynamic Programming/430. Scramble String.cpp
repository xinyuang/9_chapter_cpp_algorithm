//430. Scramble String
//1. dfs(s1 == s2 return true, s1.size() != s2.size() return false
//2. sort(s1) sort(s2)  if ss1 != ss2 return false
//3. (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
//	isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i)) ||
//	isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) &&
//	isScramble(s1.substr(i), s2.substr(0, s2.size() - i)));


class Solution {
public:
	/**
	 * @param s1: A string
	 * @param s2: Another string
	 * @return: whether s2 is a scrambled string of s1
	 */
	bool isScramble(string s1, string s2) {
		// write your code here
		if (s1 == s2) return true;
		if (s1.size() != s2.size()) return false;
		string ss1 = s1;
		sort(ss1.begin(), ss1.end());
		string ss2 = s2;
		sort(ss2.begin(), ss2.end());
		if (ss1 != ss2) return false;
		for (int i = 1; i < s1.size(); i++)
		{
			bool res = (isScramble(s1.substr(0, i), s2.substr(0, i))
				&& isScramble(s1.substr(i), s2.substr(i))
				|| isScramble(s1.substr(0, i), s2.substr(s2.size() - i))
				&& isScramble(s1.substr(i), s2.substr(0, s2.size() - i)));
			if (res) return true;
		}
		return false;
	}
};