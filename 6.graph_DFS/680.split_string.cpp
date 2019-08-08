class Solution {
public:
	/*
	 * @param : a string to be split
	 * @return: all possible split string array
	 */
	vector<vector<string>> splitString(string& s) {
		// write your code here
		vector<vector<string>> res;
		vector<string> com;
		backtrack(s, res, com, -1);

		return res;
	}

	void backtrack(string& s, vector<vector<string>>& res, vector<string>& com, int end)
	{
		if ((end + 1) == s.size())
		{
			res.push_back(com);
			return;
		}
		if (end + 1 < s.size())
		{
			com.push_back(s.substr(end + 1, 1));
			backtrack(s, res, com, end + 1);
			com.pop_back();
		}

		if (end + 2 < s.size())
		{
			com.push_back(s.substr(end + 1, 2));
			backtrack(s, res, com, end + 2);
			com.pop_back();
		}

	}
};