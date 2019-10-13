// Word break I
// dp[i] = dp[i-j]&& dict.count(s.substr(i-j,j))
class Solution {
public:
	/*
	 * @param s: A string
	 * @param dict: A dictionary of words dict
	 * @return: A boolean
	 */
	bool wordBreak(string& s, unordered_set<string>& dict) {
		// write your code here
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		int max_len = 0;
		for (auto cur : dict)
		{
			int cur_len = cur.size();
			if (cur_len > max_len) max_len = cur_len;
		}
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = 1; j <= max_len; j++)
			{
				if ((i - j) < 0) continue;
				string candidate = s.substr(i - j, j);
				if (dp[i - j] && dict.count(candidate)) dp[i] = true;
			}
		}
		return dp[s.size()];
	}
};