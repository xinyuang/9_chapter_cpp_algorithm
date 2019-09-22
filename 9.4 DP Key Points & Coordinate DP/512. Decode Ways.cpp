class Solution {
public:
	int numDecodeWay(string input) {
		// write your solution here
		int count = 0;
		search(count, input, 0);
		return count;
	}

	void search(int& count, string& input, int idx)
	{
		if (idx == input.size())
		{
			count++;
			return;
		}
		if (idx > input.size()) return;
		for (int i = 1; i <= 2; i++)
		{
			int next = stoi(input.substr(idx, i));
			if (next > 26 || next == 0 || input[idx] == '0') continue;
			search(count, input, idx + i);
		}
	}
};

class Solution {
public:
	/**
	 * @param s: a string,  encoded message
	 * @return: an integer, the number of ways decoding
	 */
	int numDecodings(string& s) {
		// write your code here
		//    010   123   f[i] = f[i-1] + f[i-2]
		if (s.size() == 0 || s[0] == '0') return 0;
		vector<int> dp(s.size(), 0);
		dp[0] = 1;
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] != '0') dp[i] = dp[i - 1];
			if (stoi(s.substr(i - 1, 2)) <= 26 && s[i - 1] != '0')
			{
				dp[i] += (i == 1 ? 1 : dp[i - 2]);
			}

			if (dp[i] == 0) return 0;
		}
		return dp[s.size() - 1];
	}
};