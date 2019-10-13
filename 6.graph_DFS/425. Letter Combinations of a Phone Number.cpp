// Letter Combinations of a Phone Number
// path.size() == digits.size() push & return
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

class Solution {
public:
	vector<string> combinations(int number) {
		// write your solution here
		unordered_map<char, string> mp = { {'2' , "abc"}, {'3' , "def"},{'4' , "ghi"},{ '5' , "jkl"},
										{ '6' , "mno"}, {'7' , "pqrs"}, {'8' , "tuv"}, {'9' , "wxyz"} };
		vector<string> res;
		string path;
		string nums = to_string(number);
		combine(res, path, mp, nums, 0);
		return res;
	}

	void combine(vector<string>& res, string& path, unordered_map<char, string>& mp, string& nums, int start)
	{
		if (start == nums.size())
		{
			res.push_back(path);
			return;
		}
		if (nums[start] == '0' || nums[start] == '1')
		{
			res.push_back("");
			return;
		}
		string candidate = mp[nums[start]];
		for (int i = 0; i < candidate.size(); i++)
		{
			path += candidate[i];
			combine(res, path, mp, nums, start + 1);
			path.pop_back();
		}
	}
};