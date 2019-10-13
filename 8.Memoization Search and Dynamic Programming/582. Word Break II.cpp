// Word Break II
// Devide and Conquer
// vector<string> res = search(idx,s,Dict,memo,max_len)
// memo[i] = result of s.substr(i)
class Solution {
public:
	/*
	 * @param s: A string
	 * @param wordDict: A set of words.
	 * @return: All possible sentences.
	 */
	vector<string> wordBreak(string& s, unordered_set<string>& wordDict) {
		// write your code here
		int max_len = 0;
		for (string word : wordDict)
		{
			max_len = max(max_len, (int)word.size());
		}
		unordered_map<string, vector<string>> mp;
		vector<string> res = Search(s, 0, wordDict, mp, max_len);
		return res;
	}

	vector<string> Search(string& s, int cur, unordered_set<string>& wordDict, unordered_map<string, vector<string>>& mp, \
		int max_len)
	{
		if (cur == s.size()) return {};
		string remain = s.substr(cur);
		if (mp.count(remain)) return mp[remain];

		vector<string> res;
		for (int i = 1; i <= max_len; i++)
		{
			string next = s.substr(cur, i);
			if (!wordDict.count(next)) continue;
			vector<string> next_comb = Search(s, cur + next.size(), wordDict, mp, max_len);

			for (string comb : next_comb)
			{
				string cur_str = next;
				cur_str += " ";
				cur_str += comb;
				res.push_back(cur_str);
			}
		}

		if (wordDict.count(remain)) res.push_back(remain);
		mp[remain] = res;
		return res;
	}
};