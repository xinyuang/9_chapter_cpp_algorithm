//423. Valid Parentheses
//stack check empty in the end

class Solution {
public:
	/**
	 * @param s: A string
	 * @return: whether the string is a valid parentheses
	 */
	bool isValidParentheses(string& s) {
		// write your code here
		stack<char> stk;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
			else
			{
				if (s[i] == ')')
				{
					if (!stk.empty() && stk.top() == '(') stk.pop();
					else return false;
				}
				if (s[i] == ']')
				{
					if (!stk.empty() && stk.top() == '[') stk.pop();
					else return false;
				}
				if (s[i] == '}')
				{
					if (!stk.empty() && stk.top() == '{') stk.pop();
					else return false;
				}
			}
		}
		return stk.empty();
	}
};