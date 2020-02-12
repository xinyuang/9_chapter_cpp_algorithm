// 386. Longest Substring with At Most K Distinct Characters
// unordered_map<char,int> mp  store character and its frequency
//    abbaes   mp.size() > k mp[s[i]] == 0 erase key
//    l   r
class Solution {
public:
	/**
	 * @param s: A string
	 * @param k: An integer
	 * @return: An integer
	 */
	int lengthOfLongestSubstringKDistinct(string& s, int k) {
		// write your code here
		int left = 0;
		unordered_map<char, int> mp;
		int max_len = 0;
		for (int i = 0; i < s.size(); i++)
		{
			mp[s[i]]++;
			while (mp.size() > k)
			{
				mp[s[left]]--;
				if (mp[s[left]] == 0) mp.erase(s[left]);
				left++;
			}
			max_len = max(max_len, i - left + 1);
		}
		return max_len;
	}
};