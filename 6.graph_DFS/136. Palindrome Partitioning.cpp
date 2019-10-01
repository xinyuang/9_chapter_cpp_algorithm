// Palindrome Partitioning
// backtrack
class Solution {
public:
	/*
	 * @param s: A string
	 * @return: A list of lists of string
	 */
	vector<vector<string>> partition(string& s) {
		// write your code here
		vector<vector<string>> res;
		vector<string> path;
		backtrack(res, path, s, 0);
		return res;
	}

	void backtrack(vector<vector<string>>& res, vector<string>& path, string& s, int s_idx)
	{
		if (s_idx == s.size())
		{
			res.push_back(path);
		}
		int remain = s.size() - s_idx;
		for (int i = 1; i <= remain; i++)
		{
			string next = s.substr(s_idx, i);
			if (!is_palindrome(next)) continue;
			path.push_back(next);
			backtrack(res, path, s, s_idx + i);
			path.pop_back();
		}
	}

	bool is_palindrome(string& str)
	{
		int left = 0, right = str.size() - 1;
		while (left < right)
		{
			if (str[left] != str[right]) return false;
			left++; right--;
		}
		return true;
	}
};

class Solution {
public:
	/*
	 * @param s: A string
	 * @return: A list of lists of string
	 */
	vector<vector<string>> partition(string& s) {
		// write your code here
		vector<string> path;
		vector<vector<string>> res;
		vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
		initDP(dp, s);
		backtrack(res, path, 0, s, dp);
		return res;
	}

	void backtrack(vector<vector<string>>& res, vector<string>& path, int start, string& s, vector<vector<bool>>& dp)
	{
		if (start >= s.size())
		{
			res.push_back(path);
			return;
		}
		int remain = s.size() - start;
		for (int j = 1; j <= remain; j++)
		{
			if (dp[start][start + j - 1] != true) continue;
			path.push_back(s.substr(start, j));

			backtrack(res, path, start + j, s, dp);
			path.pop_back();
		}
	}

	void initDP(vector<vector<bool>>& dp, string& s)
	{
		dp[s.size() - 1][s.size() - 1] = true;
		for (int i = s.size() - 2; i >= 0; i--)
		{
			dp[i][i] = true;
			for (int j = i + 1; j < s.size(); j++)
			{
				if (s[i] == s[j] && (i + 1 >= j - 1 || dp[i + 1][j - 1] == true)) dp[i][j] = true;
			}
		}
	}

};