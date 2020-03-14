//582. Word Break II
//1. devide and conqure(idx = s.size() return {})
//f(x) = f(x + idx) + target
//2. unordered_map<string, vector<string>> memo

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
		for (auto w : wordDict)
		{
			max_len = max(max_len, (int)w.size());
		}
		unordered_map<string, vector<string>> memo;
		vector<string> res = findPath(s, wordDict, 0, max_len, memo);
		return res;
	}

	vector<string> findPath(string& s, unordered_set<string>& wordDict, int idx,
		int max_len, unordered_map<string, vector<string>>& memo)
	{
		if (idx >= s.size()) return { "" };
		if (memo.count(s.substr(idx))) return memo[s.substr(idx)];
		vector<string> new_res;
		for (int i = 1; i <= max_len; i++)
		{
			if (idx + i > s.size()) continue;
			string next = s.substr(idx, i);
			if (!wordDict.count(next)) continue;
			vector<string> post = findPath(s, wordDict, idx + i, max_len, memo);

			for (string s : post)
			{
				if (s == "") s = next;
				else {
					s = next + " " + s;
				}
				new_res.push_back(s);
			}
		}
		memo[s.substr(idx)] = new_res;
		return new_res;
	}
};