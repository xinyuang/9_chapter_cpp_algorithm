//200. Longest Palindromic Substring
//
//1. for loop max(right - left + 1) s[left--] = s[right++]
//2. if (dp[i + 1][j - 1] && s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2

class Solution {
public:
	/**
	 * @param s: input string
	 * @return: the longest palindromic substring
	 */
	string longestPalindrome(string& s) {
		// write your code here
		vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
		for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
		int max_len = 0;
		string res = "";
		if (s.size() == 1) return s;
		for (int i = s.size() - 2; i >= 0; i--)
		{
			for (int j = i + 1; j < s.size(); j++)
			{
				if (s[i] == s[j] && (dp[i + 1][j - 1] || dp[i + 1][j - 1] == -1)) dp[i][j] = max(dp[i + 1][j - 1], 0) + 2;
				else dp[i][j] = 0;
				if (max_len < dp[i][j])
				{
					res = s.substr(i, j - i + 1);
					max_len = dp[i][j];
				}
			}
		}
		return res;
	}
};


//1. for loop twice, left, right pointer to find palindrom
class Solution {
public:
	/**
	 * @param s: input string
	 * @return: the longest palindromic substring
	 */
	string longestPalindrome(string& s) {
		// write your code here
		string res = "";
		for (int i = 0; i < s.size(); i++)
		{
			string odd = findOdd(s, i);
			string even = findEven(s, i);
			string cur = (odd.size() > even.size()) ? odd : even;
			res = (res.size() > cur.size()) ? res : cur;
		}
		return res;
	}

	string findOdd(string& s, int i)
	{
		int left = i, right = i;
		while (left >= 0 && right < s.size())
		{
			if (s[left] == s[right])
			{
				left--;
				right++;
			}
			else break;
		}
		string res = s.substr(left + 1, right - left - 1);
		return res;
	}

	string findEven(string& s, int i)
	{
		int left = i, right = i + 1;
		while (left >= 0 && right < s.size())
		{
			if (s[left] == s[right])
			{
				left--;
				right++;
			}
			else break;
		}
		string res = s.substr(left + 1, right - left - 1);
		return res;
	}
};