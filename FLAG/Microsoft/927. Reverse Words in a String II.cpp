//927. Reverse Words in a String II

//stack
class Solution {
public:
	/**
	 * @param str: a string
	 * @return: return a string
	 */
	string reverseWords(string& str) {
		// write your code here
		stack<string> stk;
		string tmp = "";
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ') tmp.push_back(str[i]);
			else
			{
				stk.push(tmp);
				tmp = "";
			}
		}
		if (tmp.size() != 0) stk.push(tmp);
		string res = "";
		while (!stk.empty())
		{
			res += (stk.top()) + " ";
			stk.pop();
		}
		res.pop_back();
		return res;
	}
};

//reverse each word first, then reverse whole string using swap
class Solution {
public:
	/**
	 * @param str: a string
	 * @return: return a string
	 */
	string reverseWords(string& str) {
		// write your code here
		int prev = 0;
		for (int i = 0; i <= str.size(); i++)
		{
			if (i == str.size() || str[i] == ' ')
			{
				string_swap(prev, i - 1, str);
				prev = i + 1;
			}
		}
		string_swap(0, str.size() - 1, str);
		return str;
	}

	void string_swap(int l, int r, string& str)
	{
		while (l < r)
		{
			swap(str[l], str[r]);
			l++; r--;
		}
	}
};
