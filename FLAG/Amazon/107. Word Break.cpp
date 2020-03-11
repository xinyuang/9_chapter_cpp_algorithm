107. Word Break

class Solution {
public:
	/*
	 * @param s: A string
	 * @param dict: A dictionary of words dict
	 * @return: A boolean
	 */
	bool wordBreak(string& s, unordered_set<string>& dict) {
		// write your code here
		vector<int> dp(s.size() + 1, 0);
		int max_len = 0;
		for (auto e : dict)
		{
			max_len = max(max_len, (int)e.size());
		}
		dp[0] = 1;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 1; j <= max_len; j++)
			{
				if (i - j + 1 < 0) continue;
				string sub = s.substr(i - j + 1, j);
				if (dict.count(sub)) dp[i + 1] = dp[i + 1] || dp[i - j + 1];
			}
		}
		return dp.back();
	}
};