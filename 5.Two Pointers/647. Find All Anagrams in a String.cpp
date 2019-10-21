// 647. Find All Anagrams in a String
// use sliding window to check if it's anagram
// [0-26] vector equal to the window or not
class Solution {
public:
	/**
	 * @param s: a string
	 * @param p: a string
	 * @return: a list of index
	 */
	vector<int> findAnagrams(string& s, string& p) {
		// write your code here
		vector<int> target(26, 0);
		unordered_set<char> p_set(p.begin(), p.end());
		for (int i = 0; i < p.size(); i++)
		{
			target[p[i] - 'a']++;
		}
		vector<int> candidate(26, 0);
		for (int i = 0; i < p.size(); i++)
		{
			if (target[s[i] - 'a'] > 0)candidate[s[i] - 'a']++;
		}
		int right = p.size() - 1;
		int left = 0;
		vector<int> res;
		while (right < s.size())
		{
			if (candidate == target) res.push_back(left);
			if (target[s[left] - 'a'] > 0) candidate[s[left] - 'a']--;
			left++;
			right++;
			if (target[s[right] - 'a'] > 0) candidate[s[right] - 'a']++;
		}
		return res;
	}
};