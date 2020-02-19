//369. Convert Expression to Polish Notation
//1. use stack to reverse operator (stack store low level "+-*/()") for loop i-- (A.size() - 1, 0)
//2. level: 0 : ")", 1 : "+-", 2; "*/", number directly push_back to res
//3. only operator or "(" can clean stack
//operator can clean element whose level > current operator in stack
//"(" can clean stack till ")"
//4. in the end clean whole stack
//5. reverse res

class Solution {
public:
	/**
	 * @param expression: A string array
	 * @return: The Polish notation of this expression
	 */
	vector<string> convertToPN(vector<string>& expression) {
		// write your code here
		stack<string> stk;
		vector<string> res;
		for (int i = expression.size() - 1; i >= 0; i--)
		{
			if (expression[i] == ")") stk.push(expression[i]);
			else if (expression[i] == "(")
			{
				while (stk.top() != ")") {
					res.push_back(stk.top()); stk.pop();
				}
				stk.pop();
			}
			else if (is_operator(expression[i]))
			{
				while (!stk.empty() && level(stk.top()) > level(expression[i]))
				{
					res.push_back(stk.top());
					stk.pop();
				}
				stk.push(expression[i]);
			}
			else {
				res.push_back(expression[i]);
			}
		}
		while (!stk.empty())
		{
			res.push_back(stk.top()); stk.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}

	bool is_operator(string s)
	{
		if (s == "+" || s == "-" || s == "*" || s == "/") return true;
		return false;
	}

	int level(string s)
	{
		if (s == ")") return 0;
		if (s == "+" || s == "-") return 1;
		if (s == "*" || s == "/") return 2;
		return 0;
	}
};