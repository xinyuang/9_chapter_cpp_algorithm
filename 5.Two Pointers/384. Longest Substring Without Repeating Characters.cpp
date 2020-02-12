//384. Longest Substring Without Repeating Characters
//1. left right pointer  unordered_map<char,int>, left = max(left, mp[s[i])
//2. left point to the last unique position, for i loop every time check res = max(res, i - left)
class Solution {
public:
	/**
	 * @param s: a string
	 * @return: an integer
	 */
	int lengthOfLongestSubstring(string& s) {
		// write your code here
		if (s.size() == 0) return 0;
		unordered_map<char, int> mp;
		int left = -1;
		int max_len = 1;
		for (int i = 0; i < s.size(); i++)
		{
			if (mp.count(s[i]))
			{
				left = max(left, mp[s[i]]);
			}
			mp[s[i]] = i;
			max_len = max(max_len, i - left);
		}
		return max_len;
	}
};