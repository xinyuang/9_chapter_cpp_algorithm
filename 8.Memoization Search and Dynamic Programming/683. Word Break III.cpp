// Word Break III

class Solution {
public:
	/*
	 * @param : A string
	 * @param : A set of word
	 * @return: the number of possible sentences.
	 */
	int wordBreak3(string& s, unordered_set<string>& dict) {
		// Write your code here
		unordered_map<string, int> dp;
		int max_len = 0;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		unordered_set<string> dict_;
		for (string word : dict)
		{
			max_len = max(max_len, (int)word.size());
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			dict_.insert(word);
		}
		int res = wordBreak(s, dict_, 0, dp, max_len);
		return res;
	}

	int wordBreak(string& s, unordered_set<string>& dict, int cur, unordered_map<string, int>& dp, int max_len)
	{
		if (cur == s.size()) return 0;
		string remain = s.substr(cur);
		if (dp.count(remain)) return dp[remain];
		int res = 0;
		for (int i = 1; i <= max_len; i++)
		{
			string next = s.substr(cur, i);
			if (!dict.count(next)) continue;
			int sub_res = wordBreak(s, dict, cur + next.size(), dp, max_len);
			res += sub_res;
		}
		if (dict.count(remain)) res++;
		dp[remain] = res;
		return res;
	}
};

//    s[i][j] = sum(s[i][k]*s[k+1][j])
//     -------
//    | ----  |
//    |    -  |
//     -------
class Solution {
public:
	/*
	 * @param : A string
	 * @param : A set of word
	 * @return: the number of possible sentences.
	 */
	int wordBreak3(string& s, unordered_set<string>& dict) {
		// Write your code here
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		unordered_set<string> Dict;
		for (string word : dict)
		{
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			Dict.insert(word);
		}
		vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i; j < s.size(); j++)
			{
				if (Dict.count(s.substr(i, j - i + 1))) dp[i][j] = 1;
			}
		}
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i; j < s.size(); j++)
			{
				for (int k = i; k < j; k++)
				{
					dp[i][j] += dp[i][k] * dp[k + 1][j];
				}
			}
		}
		return dp[0][s.size() - 1];
	}
};