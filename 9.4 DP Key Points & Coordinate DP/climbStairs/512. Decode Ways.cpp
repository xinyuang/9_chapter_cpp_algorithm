//512. Decode Ways
//1. dif s[0] = '0' return 0, p[0] = 1 dp[1] = 1 vector<int> dp(s.size() + 1, 0)
//2. dp[i + 1] = dp[i] + dp[i - 1] conditionally add, when meet requirement

class Solution {
public:
	/**
	 * @param s: a string,  encoded message
	 * @return: an integer, the number of ways decoding
	 */
	int numDecodings(string& s) {
		// write your code here
		if (s.size() == 0 || s[0] == '0') return 0;
		vector<int> dp(s.size() + 1);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] != '0') dp[i + 1] = dp[i];
			string cur = "";
			cur.push_back(s[i - 1]);
			cur.push_back(s[i]);
			int cur_int = stoi(cur);
			if (cur_int >= 10 && cur_int <= 26) dp[i + 1] += dp[i - 1];
		}
		return dp.back();
	}
};


// enumerate all solutions
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