class Solution {
public:
	/**
	 * @param pattern: a string,denote pattern string
	 * @param str: a string, denote matching string
	 * @return: a boolean
	 */
	bool wordPatternMatch(string& pattern, string& str) {
		// write your code here
		bool res = false;
		match(pattern, 0, str, 0, res);
		return res;
	}

	void match(string& pattern, int p_start, string& str, int s_start, bool& res)
	{
		if (p_start == pattern.size() && s_start == str.size())
		{
			res = true;
			return;
		}
		if (p_start == pattern.size() || s_start == str.size())
		{
			return;
		}

		int remain_len = str.size() - s_start;
		if (map.count(pattern[p_start]))
		{
			string expect = map[pattern[p_start]];
			int next_len = expect.size();
			string actual = str.substr(s_start, next_len);
			if (expect == actual) match(pattern, p_start + 1, str, s_start + next_len, res);
			return;
		}

		for (int i = 1; i <= remain_len; i++)
		{
			if (res) return;
			string map_str = str.substr(s_start, i);
			if (used.count(map_str)) continue;
			map[pattern[p_start]] = map_str;
			used.insert(map_str);
			match(pattern, p_start + 1, str, s_start + i, res);
			map.erase(pattern[p_start]);
			used.erase(map_str);
		}
	}

private:
	unordered_map<char, string> map;
	unordered_set<string> used;
};