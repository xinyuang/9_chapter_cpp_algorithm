class Solution {
public:
	/**
	 * @param s: an expression includes numbers, letters and brackets
	 * @return: a string
	 */
	string expressionExpand(string& s) {
		// write your code here
		int idx = 0;
		stack<char> stk;
		string res = "";
		while (idx < s.size())
		{
			if (s[idx] != ']')
			{
				stk.push(s[idx]);
			}
			else
			{
				vector<char> content;
				while (!stk.empty() && stk.top() != '[')
				{
					content.push_back(stk.top()); stk.pop();
				}
				reverse(content.begin(), content.end());
				string str_content(content.begin(), content.end());
				stk.pop();
				vector<char> digit;
				while (!stk.empty() && isdigit(stk.top()))
				{
					digit.push_back(stk.top()); stk.pop();
				}
				reverse(digit.begin(), digit.end());
				string str_digit(digit.begin(), digit.end());
				int times = stoi(str_digit);
				string subres;
				for (int i = 0; i < times; i++)
				{
					subres += str_content;
				}
				for (int i = 0; i < subres.size(); i++)
				{
					stk.push(subres[i]);
				}
			}
			idx++;
		}
		vector<char> leftover;
		while (!stk.empty())
		{
			leftover.push_back(stk.top()); stk.pop();
		}
		reverse(leftover.begin(), leftover.end());
		string str_left(leftover.begin(), leftover.end());
		if (s.back() == ']')
		{
			res = str_left + res;
		}
		else res = res + str_left;
		return res;
	}
};