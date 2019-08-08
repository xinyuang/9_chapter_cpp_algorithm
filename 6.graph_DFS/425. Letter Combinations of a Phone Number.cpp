class Solution {
public:
	/**
	 * @param digits: A digital string
	 * @return: all posible letter combinations
	 */
	vector<string> letterCombinations(string& digits) {
		// write your code here
		if (digits.size() == 0) return {};
		unordered_map<char, string> map;
		map['2'] = "abc";
		map['3'] = "def";
		map['4'] = "ghi";
		map['5'] = "jkl";
		map['6'] = "mno";
		map['7'] = "pqrs";
		map['8'] = "tuv";
		map['9'] = "wxyz";
		vector<string> res;
		string com;
		helper(digits, map, com, res, 0);
		return res;
	}

	void helper(string& digits, unordered_map<char, string>& map, string com, vector<string>& res, int start)
	{
		if (com.size() == digits.size())
		{
			res.push_back(com);
			return;
		}

		for (int j = 0; j < map[digits[start]].size(); j++)
		{
			com.push_back(map[digits[start]][j]);
			helper(digits, map, com, res, start + 1);
			com.pop_back();
		}
	}
};